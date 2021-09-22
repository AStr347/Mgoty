cmake_minimum_required(VERSION 3.5) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.




project(Mgoty)			# Название проекта

#all our files in src
set(SOURCEDIR ${PROJECT_SOURCE_DIR}/src)

# Find Boost shared libraries
if (WIN32)
	# values for find boost in windows
	# set your paths
	set(Boost_USE_STATIC_LIBS 		ON)  # only find static libs
	set(Boost_USE_DEBUG_LIBS 		ON)  # ignore debug libs and
	set(Boost_USE_RELEASE_LIBS 		ON)  # only find release libs
	set(Boost_USE_MULTITHREADED 	ON)
	set(Boost_USE_STATIC_RUNTIME    OFF)
	set(BOOST_INCLUDEDIR C:/SDK/boost_1_76_0/)
	set(BOOST_LIBRARYDIR C:/SDK/boost_1_76_0/stage/lib)
	set(BOOST_ROOT C:/SDK/boost_1_76_0/boost)
endif()

find_package(Boost)


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")

include_directories(${SOURCEDIR}/include ${Boost_INCLUDE_DIRS})# Расположение заголовочных файлов

add_executable(Mgoty
	${SOURCEDIR}/main.cpp
	${SOURCEDIR}/first.cpp
	${SOURCEDIR}/second.cpp
	${SOURCEDIR}/third.cpp
	${SOURCEDIR}/fiveth.cpp
	${SOURCEDIR}/array.cpp
	${SOURCEDIR}/string.cpp
	${SOURCEDIR}/books.cpp)	# Создает исполняемый файл с именем main

