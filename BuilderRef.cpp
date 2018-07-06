#include "BuilderRef.h"

BuilderRef::BuilderRef() {
    this->refBuilder = Gtk::Builder::create_from_file("glade2.glade");
}

Glib::RefPtr<Gtk::Builder> BuilderRef::getPtr() {
    return this->refBuilder;
}
