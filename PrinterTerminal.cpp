#include "PrinterTerminal.h"

PrinterTerminal::PrinterTerminal() : hSerial(INVALID_HANDLE_VALUE), running(false) {}

bool PrinterTerminal::connect(const std::string& port, DWORD baudRate) {
    std::string fullPortName = "\\\\.\\" + port;

    hSerial = CreateFileA(
        fullPortName.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        );

    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка: Не удалось открыть порт " << port << std::endl;
        return false;
    }

    // Настройка порта для 3D-принтера
    DCB dcb = {0};
    dcb.DCBlength = sizeof(DCB);

    if (!GetCommState(hSerial, &dcb)) {
        std::cerr << "Ошибка получения состояния порта" << std::endl;
        return false;
    }

    dcb.BaudRate = baudRate;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.Parity = NOPARITY;
    dcb.fDtrControl = DTR_CONTROL_ENABLE;
    dcb.fRtsControl = RTS_CONTROL_ENABLE;

    if (!SetCommState(hSerial, &dcb)) {
        std::cerr << "Ошибка настройки порта" << std::endl;
        return false;
    }

    // Настройка таймаутов
    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 10;
    timeouts.ReadTotalTimeoutConstant = 10;
    timeouts.ReadTotalTimeoutMultiplier = 1;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        std::cerr << "Ошибка установки таймаутов" << std::endl;
        return false;
    }

    PurgeComm(hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
    return true;
}

void PrinterTerminal::start() {
    running = true;

    std::thread readThread(&PrinterTerminal::readLoop, this);
    std::thread writeThread(&PrinterTerminal::writeLoop, this);
    std::thread consoleThread(&PrinterTerminal::consoleLoop, this);

    readThread.join();
    writeThread.join();
    consoleThread.join();
}

void PrinterTerminal::readLoop() {
    char buffer[1024];
    DWORD bytesRead;

    while (running) {
        if (ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
            if (bytesRead > 0) {
                buffer[bytesRead] = '\0';
                std::cout << buffer;
                std::cout.flush();
            }
        }
        Sleep(1);
    }
}

void PrinterTerminal::writeLoop() {
    while (running) {
        std::string command;

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueCV.wait(lock, [this]() {
                return !sendQueue.empty() || !running;
            });

            if (!running) break;

            if (!sendQueue.empty()) {
                command = sendQueue.front();
                sendQueue.pop();
            }
        }

        if (!command.empty()) {
            sendCommand(command);
        }
    }
}

void PrinterTerminal::consoleLoop() {
    std::cout << "==================================================" << std::endl;
    std::cout << "Терминал для 3D-принтера Creality Ender-3 Pro" << std::endl;
    std::cout << "Прошивка: Marlin 1.1.6.2" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "Доступные команды:" << std::endl;
    std::cout << "  gcode:  Отправить G-код (например: G28)" << std::endl;
    std::cout << "  temp:   Показать температуру" << std::endl;
    std::cout << "  status: Показать статус" << std::endl;
    std::cout << "  help:   Показать это сообщение" << std::endl;
    std::cout << "  exit:   Выход" << std::endl;
    std::cout << "==================================================" << std::endl;

    std::string input;

    while (running) {
        std::cout << "\n>>> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            running = false;
            queueCV.notify_all();
            break;
        }
        else if (input == "temp") {
            queueCommand("M105");
        }
        else if (input == "status") {
            queueCommand("M27");
            queueCommand("M119");
        }
        else if (input == "home") {
            queueCommand("G28");
        }
        else if (input == "help") {
            printHelp();
        }
        else if (!input.empty()) {
            queueCommand(input);
        }
    }
}

void PrinterTerminal::queueCommand(const std::string& command) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        sendQueue.push(command);
    }
    queueCV.notify_one();
}

void PrinterTerminal::sendCommand(const std::string& command) {
    std::string fullCommand = command + "\n";
    DWORD bytesWritten;

    std::cout << ">> " << command << std::endl;

    if (!WriteFile(hSerial, fullCommand.c_str(), fullCommand.length(), &bytesWritten, NULL)) {
        std::cerr << "Ошибка отправки команды" << std::endl;
    }
}

void PrinterTerminal::printHelp() {
    std::cout << "\nОсновные G-коды для Marlin:" << std::endl;
    std::cout << "  G28     - Автоматическая калибровка (home all)" << std::endl;
    std::cout << "  G0 X10  - Перемещение по оси X" << std::endl;
    std::cout << "  G1 Z10  - Поднять сопло на 10mm" << std::endl;
    std::cout << "  G90     - Абсолютные координаты" << std::endl;
    std::cout << "  G91     - Относительные координаты" << std::endl;
    std::cout << "  G92 E0  - Сброс экструдера" << std::endl;
    std::cout << std::endl;
    std::cout << "Основные M-коды:" << std::endl;
    std::cout << "  M104 S200 - Установить температуру экструдера" << std::endl;
    std::cout << "  M140 S60  - Установить температуру стола" << std::endl;
    std::cout << "  M105      - Получить текущую температуру" << std::endl;
    std::cout << "  M106      - Включить вентилятор" << std::endl;
    std::cout << "  M107      - Выключить вентилятор" << std::endl;
    std::cout << "  M112      - Аварийная остановка" << std::endl;
    std::cout << "  M114      - Текущая позиция" << std::endl;
    std::cout << "  M119      - Состояние концевых датчиков" << std::endl;
}

PrinterTerminal::~PrinterTerminal() {
    running = false;
    queueCV.notify_all();

    if (hSerial != INVALID_HANDLE_VALUE) {
        CloseHandle(hSerial);
    }
}
