#include "Travel.h"

void Travel::showTravelInfo()
{
    for (int i=0;i<hotels.size();i++)
    {
        cout << i + 1 << ". ";
        hotels[i].showRoomInfoBooked();
    }
    for (int i=0;i<transports.size();i++)
    {
        cout << i + 1 << ". ";
        transports[i].output();
        cout << endl;
    }
}

vector<Hotel>& Travel::getHotel()
{
    return hotels;
}

vector<Transport>& Travel::getTransport()
{
    return transports;
}






