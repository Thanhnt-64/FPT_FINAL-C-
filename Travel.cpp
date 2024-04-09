#include "Travel.h"

void Travel::showTravelInfo()
{
    for (int i=0;i<hotels.size();i++)
    {
        hotels[i].showRoomInfoBooked();
    }
    for (int i=0;i<transports.size();i++)
    {
        transports[i].output();
        cout << endl;
    }
}

vector<Hotel> Travel::getHotel()
{
    return hotels;
}

vector<Transport> Travel::getTransport()
{
    return transports;
}






