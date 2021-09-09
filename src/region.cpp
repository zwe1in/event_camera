#include "region.h"

region::region(){}

region::region(int count,
                std::vector<Event> events, int label)
{
    this->count = count;
    this->label = label;
    this->events = events;
}

region::~region()
{
    std::vector<Event> temp;
    this->events.swap(temp);
}

int region::getCount()
{
    return this->count;
}

int region::getLabel()
{
    return this->label;
}

std::vector<Event> region::getEvents()
{
    return this->events;
}

void region::setCount(int count)
{
    this->count = count;
}

void region::setLabel(int label)
{
    this->label = label;
}

void region::addEvent(Event e)
{
    this->events.push_back(e);
    this->count += 1;
}