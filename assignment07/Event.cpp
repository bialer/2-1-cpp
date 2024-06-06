#include "Event.h"

int Event::event_counter = 0;

Event::Event() {
    id = event_counter++;
}

Event::Event(string cont): content(cont) {
    id = event_counter++;
}

Event::~Event() {};

int Event::get_id() {
    return id;
}

bool Event::contains(string keyword) {
    if (content.find(keyword) != string::npos)
        return true;
    return false;
}

void Event::print(ostream &out) {
    out << id << ". ";
}

OneDayEvent::OneDayEvent() = default;
OneDayEvent::OneDayEvent(Date d, string str): Event(str), date(d) {}

bool OneDayEvent::relevant_to(Date &theDay) {
    return theDay == date;
}

bool OneDayEvent::relevant_to(Date& dayOne, Date& dayTwo) {
    return dayOne <= date && date <= dayTwo;
}

void OneDayEvent::print(ostream &out) {
    Event::print(out);
    date.print(out);
    out << ":" << content;
}

PeriodEvent::PeriodEvent() = default;
PeriodEvent::PeriodEvent(Date d1, Date d2, string str): Event(str), begin(d1), end(d2) {}

bool PeriodEvent::relevant_to(Date &theDay) {
    return begin <= theDay && theDay <= end;
}

bool PeriodEvent::relevant_to(Date& dayOne, Date& dayTwo) {
    if (begin == dayOne || begin == dayTwo || end == dayOne || end == dayTwo) return true;
    else if (begin < dayOne) return !(end < dayOne);
    else if (begin > dayOne) return begin < dayTwo;
    else return false;
}

void PeriodEvent::print(ostream &out) {
    Event::print(out);
    begin.print(out);
    out << "-";
    end.print(out);
    out << ":" << content;
}

DeadlineEvent::DeadlineEvent() = default;
DeadlineEvent::DeadlineEvent(Date d, string str): Event(str), deadline(d) {}

bool DeadlineEvent::relevant_to(Date &theDay) {
    return theDay <= deadline;
}

bool DeadlineEvent::relevant_to(Date& dayOne, Date& dayTwo) {
    return dayOne <= deadline || dayTwo <= deadline;
}

void DeadlineEvent::print(ostream &out) {
    Event::print(out);
    out << "~";
    deadline.print(out);
    out << ":" << content;
}