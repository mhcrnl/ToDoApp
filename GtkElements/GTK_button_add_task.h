#ifndef TODO_BUTTON_ADD_TASK_H
#define TODO_BUTTON_ADD_TASK_H

#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include "GTK_entry_add_task.h"
#include "GTK_tree_list_of_task.h"
#include "GTK_button_delete_task.h"
#include "GTK_button_edit_task.h"

struct GTK_button_add_task {
    //DEPS
    GTK_entry_add_task p_entry_add_task;
    GTK_tree_list_of_task p_tree_list_of_task;
    GTK_button_delete_task p_button_delete_task;
    GTK_button_edit_task p_button_edit_task;
    GTK_calendar p_calendar;

    Gtk::Button *button_add_task = nullptr;
    GTK_button_add_task(Glib::RefPtr<Gtk::Builder> builder);

    void on_button_add_task_clicked();

};

#endif //TODO_BUTTON_ADD_TASK_H
