//
// Created by dziura on 03.05.18.
//

#ifndef TODO_GTK_ENTRY_ADD_TASK_H
#define TODO_GTK_ENTRY_ADD_TASK_H

#include <gtkmm/entry.h>

struct GTK_entry_add_task {
    Gtk::Entry* entry_add_task = nullptr;
    GTK_entry_add_task(Glib::RefPtr<Gtk::Builder> builder);
};


#endif //TODO_GTK_ENTRY_ADD_TASK_H
