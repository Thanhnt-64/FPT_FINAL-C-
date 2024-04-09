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
        //Show travel info
        // Hotel Name|Room Name |Type Room |Start Time  |End Time  |Cost |Transport |Brand |From |To |Time |Cost     
        void showTravelInfo();
        
        vector<Hotel>* getHotelPrt(){
            return &hotels;
        }
        vector<Transport>* getTransportPtr(){
            return &transports;
        }
};

#endif // TRAVEL_H