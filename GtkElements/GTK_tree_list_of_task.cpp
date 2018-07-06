#include <iostream>
#include "GTK_tree_list_of_task.h"
#include "GTK_entry_add_task.h"
#include "GTK_button_add_task.h"
#include <sqlite3.h>
#include <string>

#define CB_FUNCTION(X) sigc::mem_fun( this, &GTK_tree_list_of_task::X )
#define CONNECT(X) connect( sigc::mem_fun( *this,&GTK_tree_list_of_task::X ) );

GTK_tree_list_of_task::GTK_tree_list_of_task(Glib::RefPtr<Gtk::Builder> builder, GTK_calendar* cal) : p_entry_add_task(builder), p_calendar(cal) {
    builder->get_widget("tree_list_of_task", tree_list_of_task);

    p_TreeModel = TreeModel::create();
    tree_list_of_task->set_model(p_TreeModel);
    tree_list_of_task->enable_model_drag_source();
    tree_list_of_task->enable_model_drag_dest();
    tree_list_of_task->set_activate_on_single_click(true);
    //p_TreeModel->set_sort_column(p_TreeModel->p_Columns.col_day, Gtk::SORT_ASCENDING);

    tree_list_of_task->append_column("Name", p_TreeModel->p_Columns.col_name);
    tree_list_of_task->append_column("Deadline", p_TreeModel->p_Columns.col_deadline);


    tree_list_of_task->signal_row_activated().connect(
            sigc::mem_fun(this, &GTK_tree_list_of_task::on_my_row_activated));

    readFromDB();
}

void GTK_tree_list_of_task::add_new_element(std::string text) {
    std::stringstream ss;
    guint day, month, year;
    p_calendar->calendar->get_date((guint &) year, (guint &) month, (guint &) day);
    ss << day << "/" << (month + 1) << "/" << year;
    std::string deadline = ss.str();
    unsigned int numberOfDays = day+(30*month)+(365*year);
    int myID = taskDatabase.addRecord(text, p_calendar->calendar, false);

    Gtk::TreeModel::Row row = *(p_TreeModel->append());
    row[p_TreeModel->p_Columns.col_id] = myID;
    row[p_TreeModel->p_Columns.col_name] = text;
    row[p_TreeModel->p_Columns.col_deadline] = deadline;
    row[p_TreeModel->p_Columns.col_day] = day;
    row[p_TreeModel->p_Columns.col_month] = month;
    row[p_TreeModel->p_Columns.col_year] = year;
    row[p_TreeModel->p_Columns.sum_of_days] = numberOfDays;
    row[p_TreeModel->p_Columns.col_done] = false;

    p_TreeModel->set_sort_column(p_TreeModel->p_Columns.sum_of_days, Gtk::SORT_ASCENDING);

    std::cout << "#Added: " << row[p_TreeModel->p_Columns.col_name] << std::endl;
}


void GTK_tree_list_of_task::on_my_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column) {
    isSelected = 1;
    auto iter = p_TreeModel->get_iter(path);

    if (iter) {
        Gtk::TreeModel::Row row = *iter;
        current_row = row;
        p_entry_add_task.entry_add_task->set_text(row[p_TreeModel->p_Columns.col_name]);

        auto day = row[p_TreeModel->p_Columns.col_day];
        auto month = row[p_TreeModel->p_Columns.col_month];
        auto year = row[p_TreeModel->p_Columns.col_year];
        p_calendar->calendar->select_month(month,year);
        p_calendar->calendar->select_day(day);
        std::cout << "#Selected: " << row[p_TreeModel->p_Columns.col_name] << std::endl;
    }
}

void GTK_tree_list_of_task::delete_row() {

    Gtk::TreeModel::Row row = *current_row;
    std::cout << "#Deleted: " << row[p_TreeModel->p_Columns.col_name] << std::endl;
    taskDatabase.deleteRecord(row[p_TreeModel->p_Columns.col_id]);
    p_TreeModel->erase(current_row);
    p_entry_add_task.entry_add_task->set_text("");
    isSelected = 0;
    p_TreeModel->set_sort_column(p_TreeModel->p_Columns.sum_of_days, Gtk::SORT_ASCENDING);
}

void GTK_tree_list_of_task::update_row() {
    std::stringstream ss;
    guint day, month, year;
    p_calendar->calendar->get_date((guint &) year, (guint &) month, (guint &) day);
    ss << day << "/" << month + 1 << "/" << year;
    unsigned int numberOfDays = day+(30*month)+(365*year);
    std::string deadline = ss.str();

    ToDoTask tmp;
    Gtk::TreeModel::Row row = *current_row;
    tmp.id = row[p_TreeModel->p_Columns.col_id];
    tmp.text = p_entry_add_task.entry_add_task->get_text();
    tmp.day = day;
    tmp.month = month;
    tmp.year = year;
    tmp.done = row[p_TreeModel->p_Columns.col_done];
    row[p_TreeModel->p_Columns.col_name] = tmp.text;
    row[p_TreeModel->p_Columns.col_day] = tmp.day;
    row[p_TreeModel->p_Columns.col_month] = tmp.month;
    row[p_TreeModel->p_Columns.col_year] = tmp.year;
    row[p_TreeModel->p_Columns.col_deadline] = deadline;
    row[p_TreeModel->p_Columns.sum_of_days] = numberOfDays;
    taskDatabase.updateRecord(tmp);
    p_entry_add_task.entry_add_task->set_text("");
    std::cout << "#Updated: " << tmp.text << std::endl;
    isSelected = 0;
    p_TreeModel->set_sort_column(p_TreeModel->p_Columns.sum_of_days, Gtk::SORT_ASCENDING);
}

void GTK_tree_list_of_task::readFromDB() {
    auto storage = TaskDatabase::connectDB();
    auto allTasks = storage.get_all<ToDoTask>();
    for (auto const &curr : allTasks) {
        Gtk::Calendar cal;
        std::stringstream ss;
        ss << curr.day << "/" << curr.month+1 << "/" << curr.year;
        unsigned int numberOfDays = curr.day+(30*curr.month)+(365*curr.year);

        std::string deadline = ss.str();

        Gtk::TreeModel::Row row = *(p_TreeModel->append());
        row[p_TreeModel->p_Columns.col_id] = curr.id;
        row[p_TreeModel->p_Columns.col_name] = curr.text;
        row[p_TreeModel->p_Columns.col_day] = curr.day;
        row[p_TreeModel->p_Columns.col_month] = curr.month;
        row[p_TreeModel->p_Columns.col_year] = curr.year;
        row[p_TreeModel->p_Columns.col_deadline] = deadline;
        row[p_TreeModel->p_Columns.sum_of_days] = numberOfDays;
        row[p_TreeModel->p_Columns.col_done] = curr.done;
    }
    std::cout << "#LoadedRecordsFromDB " << std::endl;
    p_TreeModel->set_sort_column(p_TreeModel->p_Columns.sum_of_days, Gtk::SORT_ASCENDING);
}

void GTK_tree_list_of_task::on_button_checkbox_clicked() {
    std::cout << "Checkboc clicked";
}

void
GTK_tree_list_of_task::foocolData(Gtk::CellRenderer *renderer, const Gtk::TreeModel::iterator &iter) {
    std::cout << "foocolData " << this << "\n";
}

void
GTK_tree_list_of_task::foocolToggled(const Glib::ustring &path) {
    std::cout << "foocolToggled " << "\n";
    auto it = p_TreeModel->get_iter(path);

    Gtk::TreeModel::iterator iter = p_TreeModel->get_iter(path);
    if (iter) {
        Gtk::TreeModel::Row row = *iter;

        row[p_TreeModel->p_Columns.col_done] = true;
        row.set_value(3, true);

    }
}

void
GTK_tree_list_of_task::foocolToggled2(Gtk::CellRendererToggle &it, const Glib::ustring &path) {
    std::cout << "foocolToggled " << "\n";
    auto iit = p_TreeModel->get_iter(path);

    Gtk::TreeModel::iterator iter = p_TreeModel->get_iter(path);
    if (iter) {
        Gtk::TreeModel::Row row = *iter;

        row[p_TreeModel->p_Columns.col_done] = true;

    }
}
