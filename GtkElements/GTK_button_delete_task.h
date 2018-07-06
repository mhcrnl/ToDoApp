#ifndef TODO_BUTTON_DELETE_TASK_H
#define TODO_BUTTON_DELETE_TASK_H

#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include "GTK_entry_add_task.h"
#include "GTK_tree_list_of_task.h"

struct GTK_button_delete_task {
    //DEPS
    GTK_entry_add_task p_entry_add_task;
    GTK_tree_list_of_task* p_tree_list_of_task;


    Gtk::Button *button_delete_task = nullptr;
    GTK_button_delete_task(Glib::RefPtr<Gtk::Builder> builder, GTK_tree_list_of_task* gtk_tree_list_of_task);

    void on_button_delete_task_clicked();
};

#endif //TODO_BUTTON_DELETE_TASK_H
