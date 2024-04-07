#ifndef TRAVEL_H
#define TRAVEL_H

#include "Hotel.h"
#include "Transport.h"
#include <vector>
class Travel{
    private:
        vector<Hotel> hotels;
        vector<Transport> transports;
    public:
        void showTravelInfo();
        void changeTravelInfo();
        void cancelTravel();
}

#endif // TRAVEL_H