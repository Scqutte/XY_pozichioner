#ifndef PRINTERTERMINAL_H
#define PRINTERTERMINAL_H

#include <windows.h>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>
#include <thread>

class PrinterTerminal {
private:
    HANDLE hSerial;
    std::atomic<bool> running;
    std::queue<std::string> sendQueue;
    std::mutex queueMutex;
    std::condition_variable queueCV;

    // Private methods
    void readLoop();
    void writeLoop();
    void consoleLoop();
    void sendCommand(const std::string& command);
    void printHelp();

public:
    PrinterTerminal();
    ~PrinterTerminal();

    bool connect(const std::string& port = "COM3", DWORD baudRate = 115200);
    void start();
    void queueCommand(const std::string& command);
};

#endif // PRINTERTERMINAL_H
