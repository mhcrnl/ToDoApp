#include <iostream>
#include "GTK_button_delete_task.h"

GTK_button_delete_task::GTK_button_delete_task(Glib::RefPtr<Gtk::Builder> builder, GTK_tree_list_of_task* list) : p_entry_add_task(builder), p_tree_list_of_task(list) {
    builder->get_widget("button_delete_task", button_delete_task);
    button_delete_task->signal_clicked().connect(sigc::mem_fun(*this, &GTK_button_delete_task::on_button_delete_task_clicked));
    //button_delete_task->signal_popup_menu();
}

void GTK_button_delete_task::on_button_delete_task_clicked() {
    if(p_tree_list_of_task->isSelected==1) {
        p_tree_list_of_task->delete_row();
    }
}
