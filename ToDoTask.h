//
// Created by dziura on 04.06.18.
//

#ifndef TODO_TODOTASK_H
#define TODO_TODOTASK_H

#include <gtkmm/builder.h>
#include "GtkElements/GTK_calendar.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

struct ToDoTask {
    int id;
    std::string text;

    //Glib::ustring describe;
    //Glib::ustring deadline;
    int day, month, year, done;
    //GTK_calendar p_calendar;

    //ToDoTask(Glib::RefPtr<Gtk::Builder> builder);
};

struct TaskDatabase {

    TaskDatabase();

    static sqlite_orm::internal::storage_t<sqlite_orm::table_t<sqlite_orm::internal::column_t<ToDoTask, int, sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<ToDoTask, std::string>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>>>
    connectDB();

    int addRecord(std::string text, Gtk::Calendar* date, bool done);

    void viewRecord(int id);

    ToDoTask getRecord(int id);

    void deleteRecord(int id);

    void updateRecord(ToDoTask &toDoTask);
};



#endif //TODO_TODOTASK_H
