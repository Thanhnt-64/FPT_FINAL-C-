#include "Lib/Travel.h"

void Travel::showTravelInfo()
{
    for (int i = 0; i < hotels.size(); i++)
    {
        cout << i + 1 << ". ";
        hotels[i].showRoomInfoBooked();
    }
    cout << endl;
    for (int i = 0; i < transports.size(); i++)
    {
        cout << i + 1 << ". ";
        transports[i].output();
    }
}

vector<Hotel> &Travel::getHotel()
{
    return hotels;
}

vector<Transport> &Travel::getTransport()
{
    return transports;
}

Travel::Travel(vector<Hotel> hotels, vector<Transport> trans, string namePlace, int travelCost)
    : hotels(hotels), transports(trans), namePlace(namePlace), travelCost(travelCost) {}
