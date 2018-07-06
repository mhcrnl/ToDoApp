#include "ToDoWindow.h"
#include "GtkElements/GTK_button_add_task.h"

ToDoWindow::ToDoWindow(Glib::RefPtr<Gtk::Builder> builder) : p_button_add_task(builder) {
    builder->get_widget("window_todo_app",window_todo_app);
}
