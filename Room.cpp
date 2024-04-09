#include "Room.h"

void Room::setCost(int cost)
{
    m_cost = cost;
}

Room Room::operator=(const Room& obj)
{
    m_name = obj.m_name;
    m_startTime = obj.m_startTime;
    m_endTime = obj.m_endTime;
    m_typeRoom = obj.m_typeRoom;
    m_cost = obj.m_cost;
    return *this;
}

Room::Room(string name, string startTime , string endTime , string typeRoom, int cost)
    : m_name{name}, m_startTime{startTime}, m_endTime{endTime}, m_typeRoom{typeRoom}, m_cost{cost}
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