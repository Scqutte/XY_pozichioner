# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\XY_pozicioner_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\XY_pozicioner_autogen.dir\\ParseCache.txt"
  "XY_pozicioner_autogen"
  )
endif()
