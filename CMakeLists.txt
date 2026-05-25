cmake_minimum_required(VERSION 3.14)
project(MonsterAdapter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека с классами (header-only, но для порядка можно указать)
add_library(adapter_lib INTERFACE)
target_include_directories(adapter_lib INTERFACE src)

# Демо-приложение
add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE adapter_lib)

# Тесты
enable_testing()
add_subdirectory(tests)

# ---------- CPack: DEB-пакет ----------
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Student")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME "monsteradapter")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Adapter pattern demo (Monster to Pet)")
install(TARGETS demo RUNTIME DESTINATION bin)
install(DIRECTORY src/ DESTINATION include/monsteradapter FILES_MATCHING PATTERN "*.h")

include(CPack)
