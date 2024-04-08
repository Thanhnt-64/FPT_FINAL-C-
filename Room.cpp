#include "Room.h"

Room ::Room(string name = nonestring, string startTime = nonestring, string endTime = nonestring, string typeRoom = nonestring)
    : m_name{name}, m_startTime{startTime}, m_endTime{endTime}, m_typeRoom{typeRoom}
{
}

void Room::setName(string name)
{
    m_name = name;
}

void Room::setStartTime(string startTime)
{
    m_startTime = startTime;
}

void Room::setEndTime(string endTime)
{
    m_endTime = endTime;
}

void Room::setTypeRoom(string typeRoom)
{
    m_typeRoom = typeRoom;
}

void Room::setEndTime(string endTime)
{
    m_endTime = endTime;
}

string Room::getName()
{
    return m_name;
}

string Room::getStartTime()
{
    return  m_startTime;
}

string Room::getEndTime()
{
    return m_endTime;
}

string Room::getTypeRoom()
{
    return m_typeRoom;
}

int Room::getCost()
{
    return m_cost;
}