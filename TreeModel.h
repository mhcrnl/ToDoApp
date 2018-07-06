#ifndef GTKMM_EXAMPLE_TREEMODEL_DND_H
#define GTKMM_EXAMPLE_TREEMODEL_DND_H


#include <gtkmm.h>
#include "ToDoTask.h"


class TreeModel : public Gtk::TreeStore
{
protected:
    TreeModel();

public:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:
        ModelColumns() {
            add(col_id);
            add(col_name);
            add(col_day);
            add(col_month);
            add(col_year);
            add(sum_of_days);
            add(col_deadline);
            add(col_done);
        }
        //ToDoTask task;
        Gtk::TreeModelColumn<int> col_id;
        Gtk::TreeModelColumn<Glib::ustring> col_name;
        Gtk::TreeModelColumn<int> col_day;
        Gtk::TreeModelColumn<int> col_month;
        Gtk::TreeModelColumn<int> col_year;
        Gtk::TreeModelColumn<unsigned int> sum_of_days;
        Gtk::TreeModelColumn<Glib::ustring> col_deadline;
        Gtk::TreeModelColumn<bool> col_done;
    };

    ModelColumns p_Columns;
    static Glib::RefPtr<TreeModel> create();

    //bool row_drop_possible_vfunc(const Path &dest, const Gtk::SelectionData &selection_data) const;
};

#endif //GTKMM_EXAMPLE_TREEMODEL_DND_H