#ifndef TODO_BUILDERREF_H
#define TODO_BUILDERREF_H

#include <iostream>
#include <gtkmm/builder.h>

class BuilderRef {
private:
    Glib::RefPtr<Gtk::Builder> refBuilder;
public:
    BuilderRef();

    Glib::RefPtr<Gtk::Builder> getPtr();
};


#endif //TODO_BUILDERREF_H
