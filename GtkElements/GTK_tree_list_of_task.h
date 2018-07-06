//
// Created by dziura on 04.05.18.
//

#ifndef TODO_GTK_TREE_LIST_OF_TASK_H
#define TODO_GTK_TREE_LIST_OF_TASK_H


#include <gtkmm/treeview.h>
#include <gtkmm/builder.h>
#include "../TreeModel.h"
#include "GTK_entry_add_task.h"

struct GTK_tree_list_of_task {
    GTK_tree_list_of_task(Glib::RefPtr<Gtk::Builder> builder, GTK_calendar* cal);

    Gtk::TreeView *tree_list_of_task = nullptr;
    Glib::RefPtr<TreeModel> p_TreeModel;
    GTK_entry_add_task p_entry_add_task;
    GTK_calendar* p_calendar;

    TaskDatabase taskDatabase;
    Gtk::TreeView::Column checkbox_column;
    Gtk::CellRendererToggle p_checkbox;
    Gtk::CellRendererToggle fooRenderer;
    Gtk::CellRendererToggle *pRenderer;
    Gtk::CheckButton checkbutton;
    Gtk::TreeModel::Row current_row{};

    int isSelected = 0;

    void on_my_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column);

    void add_new_element(std::string text);

    void readFromDB();

  void on_button_checkbox_clicked();
    void foocolData(Gtk::CellRenderer*,const Gtk::TreeModel::iterator&);
    void foocolToggled(const Glib::ustring&);

    void foocolToggled2(Gtk::CellRendererToggle &it, const Glib::ustring &path);

    void delete_row();

    void update_row();
};


#endif //TODO_GTK_TREE_LIST_OF_TASK_H
