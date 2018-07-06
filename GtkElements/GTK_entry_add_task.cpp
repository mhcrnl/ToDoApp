//
// Created by dziura on 03.05.18.
//

#include <gtkmm/builder.h>
#include "GTK_entry_add_task.h"

GTK_entry_add_task::GTK_entry_add_task(Glib::RefPtr<Gtk::Builder> builder) {
    builder->get_widget("entry_add_task", entry_add_task);
}