#include <iostream>
#include "GTK_button_edit_task.h"

GTK_button_edit_task::GTK_button_edit_task(Glib::RefPtr<Gtk::Builder> builder, GTK_tree_list_of_task* list) : p_entry_add_task(builder), p_tree_list_of_task(list) {
    builder->get_widget("button_edit_task", button_edit_task);
    button_edit_task->signal_clicked().connect(sigc::mem_fun(*this, &GTK_button_edit_task::on_button_edit_task_clicked));
    button_edit_task->signal_popup_menu();
}

void GTK_button_edit_task::on_button_edit_task_clicked() {
    if(p_tree_list_of_task->isSelected==1) {
        p_tree_list_of_task->update_row();
    }
}

void GTK_button_edit_task::on_button_edit_task_edit() {

}

