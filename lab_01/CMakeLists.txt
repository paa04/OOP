cmake_minimum_required(VERSION 3.5)

project(MyQtProject)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ui
)

# Найдите пакет Qt
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

QT6_WRAP_UI( UI_HEADERS ui/MainWindow.ui )

include_directories(${CMAKE_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/build)

# Добавьте исполняемый файл
add_executable(MyQtApp ./src/edges.cpp ./src/point.cpp ./src/figure.cpp ./src/allocate.cpp ./src/io.cpp ./src/main.cpp ./src/mainwindow.cpp ./inc/mainwindow.h ./build/ui_MainWindow.h ${UI_HEADERS}
        inc/events.h
        src/events.cpp
        inc/requests.h
        src/requests.cpp
        inc/draw.h
        src/draw.cpp
        inc/error.h
        src/math_f.cpp
        inc/math_f.h
        src/error.cpp
        src/backup.cpp
        inc/backup.h)

# Связать библиотеки Qt с вашим исполняемым файлом
target_link_libraries(MyQtApp PRIVATE Qt6::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyQtApp)
endif()