//
// Created by dziura on 04.06.18.
//

#ifndef TODO_GTK_CALENDAR_H
#define TODO_GTK_CALENDAR_H


#include <gtkmm/calendar.h>
#include <gtkmm/builder.h>

struct GTK_calendar {
    Gtk::Calendar *calendar = nullptr;
    GTK_calendar(Glib::RefPtr<Gtk::Builder> builder);
};


#endif //TODO_GTK_CALENDAR_H
