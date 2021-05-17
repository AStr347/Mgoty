cmake_minimum_required(VERSION 3.5) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.




project(Mgoty)			# Название проекта

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

include_directories(${PROJECT_SOURCE_DIR}/include)# Расположение заголовочных файлов

add_executable(Mgoty main.cpp first.cpp second.cpp third.cpp)	# Создает исполняемый файл с именем main

