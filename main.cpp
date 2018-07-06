#include <iostream>
#include "ToDoWindow.h"
#include "TreeModel.h"
#include "BuilderRef.h"

void on_button_add_task_clicked(Glib::RefPtr<Gtk::Builder> tet);

struct User {
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::shared_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
    std::string comment;
};

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    BuilderRef Builder;

    ToDoWindow ToDoApp(Builder.getPtr());

    auto css = Gtk::CssProvider::create();
    if(not css->load_from_path("mystyle.css")) {
        std::cerr << "Failed to load css\n";
        std::exit(1);
    }
    auto screen = Gdk::Screen::get_default();
    ToDoApp.window_todo_app->get_style_context()->add_provider_for_screen(screen, css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    app->run(*ToDoApp.window_todo_app);

    return 0;
}



