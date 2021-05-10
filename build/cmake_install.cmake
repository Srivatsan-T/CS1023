# Install script for directory: C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/FMT")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Strawberry/c/bin/objdump.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/fmt-config.cmake"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/fmt-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake"
         "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/CMakeFiles/Export/lib/cmake/fmt/fmt-targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/libfmtd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/$<TARGET_PDB_FILE:fmt"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/fmt-header-only>"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/fmt" TYPE FILE FILES
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/chrono.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/color.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/compile.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/core.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/format.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/format-inl.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/locale.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/os.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/ostream.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/posix.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/printf.h"
    "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/include/fmt/ranges.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/fmt.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/doc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
