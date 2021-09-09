#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include<vector>
struct Event
{
//    double time;
    int x;
    int y;
//    int p;

    Event( int _x, int _y) : x(_x), y(_y){}
};

class Frame
{
private:
    std::vector<Event> events;  // 事件点序列
    int count;  // 时间点个数
    int width;
    int height;
public:
    Frame(/* args */);
    Frame(std::vector<Event> events, int count);
    Frame(std::vector<Event> events, int count, int width, int height);
    std::vector<Event> getEvents();
    int getCount();
    int getWidth();
    int getHeight();
    void setCount(int count);
    void setEvents(std::vector<Event> events);
    ~Frame();
};


#endif