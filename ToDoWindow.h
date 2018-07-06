#ifndef TODO_TODOWINDOW_H
#define TODO_TODOWINDOW_H

#include <gtkmm.h>
#include "GtkElements/GTK_button_add_task.h"
#include "GtkElements/GTK_tree_list_of_task.h"
#include "GtkElements/GTK_button_delete_task.h"
#include "GtkElements/GTK_button_edit_task.h"

struct ToDoWindow {

    Gtk::Window* window_todo_app = nullptr;
    GTK_button_add_task p_button_add_task;
    //GTK_button_delete_task p_button_delete_task;
    //GTK_button_edit_task p_button_edit_task;

    ToDoWindow(Glib::RefPtr<Gtk::Builder> builder);
};


#endif //TODO_TODOWINDOW_H
