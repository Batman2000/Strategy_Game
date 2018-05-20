cmake_minimum_required(VERSION 3.2)
project(my_first_real_strategy)
enable_testing()
unset(WITH_TESTS CACHE)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")
set(SOURCES_FILES2 "tester.cpp")
set(SOURCE_FILES main.cpp main_lib.h human_tree.h dark_fraction.h tests.h squad.h army.h wrap.h base_decorator.h surface_decorator.h air_decorator.h client_adapter.h)
if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
endif()
if (WITH_TEST)

    add_executable(runTests ${SOURCES_FILES2})
    target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
else()
    add_executable(my_first_real_strategy ${SOURCE_FILES})
endif()
# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
