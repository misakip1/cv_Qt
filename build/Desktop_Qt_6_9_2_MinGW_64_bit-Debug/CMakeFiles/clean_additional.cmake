# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\opencv_invoke_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\opencv_invoke_autogen.dir\\ParseCache.txt"
  "opencv_invoke_autogen"
  )
endif()
