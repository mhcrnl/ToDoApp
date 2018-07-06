//
// Created by dziura on 04.06.18.
//

#include "ToDoTask.h"
#include <gtkmm.h>


TaskDatabase::TaskDatabase() {

}

sqlite_orm::internal::storage_t<sqlite_orm::table_t<sqlite_orm::internal::column_t<ToDoTask, int, sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<ToDoTask, std::string>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>, sqlite_orm::internal::column_t<ToDoTask, int>>>
TaskDatabase::connectDB() {
    auto storage = sqlite_orm::make_storage("todo.sqlite",
                                            sqlite_orm::make_table("tasks",
                                                                   sqlite_orm::make_column("id", &ToDoTask::id,
                                                                                           sqlite_orm::autoincrement(),
                                                                                           sqlite_orm::primary_key()),
                                                                   sqlite_orm::make_column("name", &ToDoTask::text),
                                                                   sqlite_orm::make_column("day", &ToDoTask::day),
                                                                   sqlite_orm::make_column("month", &ToDoTask::month),
                                                                   sqlite_orm::make_column("year", &ToDoTask::year),
                                                                   sqlite_orm::make_column("done", &ToDoTask::done)));
    storage.sync_schema();
    return storage;
}

int TaskDatabase::addRecord(std::string text, Gtk::Calendar *date, bool done) {
    guint day, month, year;
    date->get_date((guint &) year, (guint &) month, (guint &) day);

    auto storage = connectDB();
    auto insertedId = storage.insert(ToDoTask{
            1,
            text,
            day,
            month,
            year,
            done
    });
    //viewRecord(insertedId);
    return insertedId;
}

void TaskDatabase::viewRecord(int id) {
    auto storage = connectDB();
    auto record = storage.get<ToDoTask>(id);
    std::cout << "View Record" << storage.dump(record) << std::endl;
}

ToDoTask TaskDatabase::getRecord(int id) {
    auto storage = connectDB();
    auto record = storage.get<ToDoTask>(id);
    //std::cout << "Get Record:" << storage.dump(record) << std::endl;
    return record;
}

void TaskDatabase::deleteRecord(int id) {
    auto storage = connectDB();
    //std::cout << "Deleted Record: " << storage.dump(id) << std::endl;
    storage.remove<ToDoTask>(id);
}

void TaskDatabase::updateRecord(ToDoTask &toDoTask) {
    auto storage = connectDB();
    //std::cout << "Deleted Record: " << storage.dump(id) << std::endl;
    storage.update(toDoTask);
}

