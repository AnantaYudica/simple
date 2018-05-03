cmake_minimum_required (VERSION 2.8)

add_compile_options(-std=c++11)

project (simple)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories (${PROJECT_SOURCE_DIR}/../include)
