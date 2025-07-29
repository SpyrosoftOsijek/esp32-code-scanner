# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/version.cmake)

# Add newly added components to one of these lines:
# 1. Add here if the component is compatible with IDF >= v4.3
set(EXTRA_COMPONENT_DIRS
    "../components"
    "../components/cam"
)

set(TEST_COMPONENTS "cam")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(init_project_test)