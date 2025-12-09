cmake_minimum_required(VERSION 3.5)
project(HealthTracker)

set(CMAKE_CXX_STANDARD 17)

# Activa AUTOMOC, AUTOUIC y AUTORCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Sql REQUIRED)

# Archivos fuente .cpp
set(SOURCES
    main.cpp
    User.cpp
    DatabaseManager.cpp
    LoginWindow.cpp
    RegisterWindow.cpp
    MainWindow.cpp
    HealthRecord.cpp
    HealthAnalyzer.cpp
    CSVExporter.cpp
)

# Archivos .h
set(HEADERS
    User.h
    DatabaseManager.h
    LoginWindow.h
    RegisterWindow.h
    MainWindow.h
    HealthRecord.h
    HealthAnalyzer.h
    CSVExporter.h
)

# Archivos .ui
set(UI_FILES
    LoginWindow.ui
    RegisterWindow.ui
    MainWindow.ui
)

# Ejecutable
add_executable(HealthTracker
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# Linkeo con Qt5
target_link_libraries(HealthTracker
    Qt5::Core
    Qt5::Widgets
    Qt5::Sql
)
