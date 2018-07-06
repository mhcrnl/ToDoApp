#include <iostream>
#include "GTK_button_add_task.h"

GTK_button_add_task::GTK_button_add_task(Glib::RefPtr<Gtk::Builder> builder) : p_entry_add_task(builder),
                                                                               p_tree_list_of_task(builder, &p_calendar),
                                                                               p_calendar(builder),
                                                                               p_button_delete_task(builder,
                                                                                                    &p_tree_list_of_task),
                                                                               p_button_edit_task(builder,
                                                                                                  &p_tree_list_of_task) {
    builder->get_widget("button_add_task", button_add_task);
    button_add_task->signal_clicked().connect(sigc::mem_fun(*this, &GTK_button_add_task::on_button_add_task_clicked));
    button_add_task->signal_popup_menu();
}

void GTK_button_add_task::on_button_add_task_clicked() {
    auto text = this->p_entry_add_task.entry_add_task->get_text();
    if(!text.empty()) {
        p_tree_list_of_task.add_new_element(text);
        this->p_entry_add_task.entry_add_task->set_text("");
    }
}

