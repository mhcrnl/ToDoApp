//
// Created by dziura on 04.06.18.
//

#include "GTK_calendar.h"

GTK_calendar::GTK_calendar(Glib::RefPtr<Gtk::Builder> builder) {
    builder->get_widget("calendar", calendar);
}
