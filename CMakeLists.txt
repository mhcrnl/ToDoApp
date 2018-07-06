cmake_minimum_required(VERSION 3.10)
project(Todo)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

find_package(SQLiteCpp CONFIG REQUIRED)
find_package(sqlite3 CONFIG REQUIRED)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(Todo main.cpp TreeModel.cpp BuilderRef.cpp BuilderRef.h GtkElements/GTK_button_add_task.cpp GtkElements/GTK_button_add_task.h GtkElements/GTK_entry_add_task.cpp GtkElements/GTK_entry_add_task.h ToDoWindow.cpp ToDoWindow.h GtkElements/GTK_tree_list_of_task.cpp GtkElements/GTK_button_delete_task.cpp GtkElements/GTK_button_delete_task.h GtkElements/GTK_button_edit_task.cpp GtkElements/GTK_button_edit_task.h GtkElements/GTK_tree_list_of_task.h ToDoTask.cpp ToDoTask.h GtkElements/GTK_calendar.cpp GtkElements/GTK_calendar.h)

target_link_libraries(Todo ${GTKMM_LIBRARIES} SQLiteCpp sqlite3)




