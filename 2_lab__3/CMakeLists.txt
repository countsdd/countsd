cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME 2lab_3)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

# Создаем библиотеку
add_library(clock_lib STATIC src/clock_lib.cpp)

# Указываем пути к заголовочным файлам
target_include_directories(clock_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Создаем исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp Clock.cpp)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries("${PROJECT_NAME}" clock_lib)

# Добавляем путь к заголовкам для исполняемого файла
target_include_directories("${PROJECT_NAME}" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})