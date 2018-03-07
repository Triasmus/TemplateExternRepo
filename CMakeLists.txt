cmake_minimum_required(VERSION 3.2.2)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR} CACHE PATH
  "Locaction for installation"
  FORCE)
set(CMAKE_CONFIGURATION_TYPES Release Debug)
set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING "The needed configuration" FORCE)
project(TemplateExternRepo)
include (version.cmake)
enable_testing()
set(externpro_DIR "C:/Program Files/externpro 18.01.1-vc140-64")
list(APPEND XP_MODULE_PATH ${externpro_DIR}/share/cmake)
include(${externpro_DIR}/share/cmake/xpfunmac.cmake)
xpCommonFlags()

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -pedantic -Wextra")
else()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(Shared)
add_subdirectory(Executable)
add_subdirectory(Playground)
