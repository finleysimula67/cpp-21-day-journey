cmake_minimum_required(VERSION 3.21)

project(ExpenseTracker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(ExpenseTracker
    main.cpp
    src/Expense.cpp
    include/Expense.h
    src/MainWindow.cpp
    include/MainWindow.h
)

target_link_libraries(ExpenseTracker PRIVATE
    Qt6::Widgets
)

target_include_directories(ExpenseTracker PRIVATE
    include
)