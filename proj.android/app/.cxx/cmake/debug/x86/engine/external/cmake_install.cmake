# Install script for directory: C:/Users/Khoa/Documents/GitHub/Allegro-Learning/cocos2d/external

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/AllegroLearning")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/Box2D/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/chipmunk/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/freetype2/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/recast/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/bullet/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/jpeg/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/openssl/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/uv/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/webp/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/websockets/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/tinyxml2/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/xxhash/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/xxtea/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/clipper/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/edtaa3func/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/ConvertUTF/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/poly2tri/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/md5/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/curl/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/png/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/android-specific/cpufeatures/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/android-specific/pvmp3dec/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/android-specific/tremolo/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/zlib/cmake_install.cmake")
  include("C:/Users/Khoa/Documents/GitHub/Allegro-Learning/proj.android/app/.cxx/cmake/debug/x86/engine/external/unzip/cmake_install.cmake")

endif()

