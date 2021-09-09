#ifndef REGION_H
#define REGIOIN_H

#include <iostream>
#include "event.h"

class region
{
private:
    std::vector<Event> events;  //事件点序列
    int count;  // 时间点个数
    int label;  // 区域标识
public:
    region();
    region(int count, std::vector<Event> events, int label);
    ~region();
    int getCount();
    int getLabel();
    std::vector<Event> getEvents();
    void setCount(int count);
    void setLabel(int label);
    void addEvent(Event e);
};

#endif