#include "event.h"

Frame::Frame(){}

Frame::Frame(std::vector<Event> events, int count)
{
    this->events = events;
    this->count = count;
}

Frame::Frame(std::vector<Event> events, int count, int width, int height)
{
    this->events = events;
    this->count = count;
    this->width = width;
    this->height = height;
}

std::vector<Event> Frame::getEvents()
{
    return this->events;
}

int Frame::getCount()
{
    return this->count;
}

int Frame::getWidth()
{
    return this->width;
}

int Frame::getHeight()
{
    return this->height;
}

void Frame::setCount(int count)
{
    this->count = count;
}

void Frame::setEvents(std::vector<Event> events)
{
    this->events = events;
}

Frame::~Frame(){}