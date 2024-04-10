#ifndef TRAVEL_H
#define TRAVEL_H

#include "Hotel.h"
#include "Transport.h"
#include <vector>
class Travel{
    private:
        vector<Hotel> hotels;
        vector<Transport> transports;
        string namePlace;
    public:
        Travel(vector <Hotel> hotel,vector <Transport> trans );
        //Show travel info
        // Hotel Name|Room Name |Type Room |Start Time  |End Time  |Cost |Transport |Brand |From |To |Time |Cost     
        void showTravelInfo();
        vector<Hotel>& getHotel();
        vector<Transport>& getTransport();
        void setPlace(){
            cout << "Enter new place: ";
            getline(cin, namePlace);
        }
        string getPlace(){
            return namePlace;
        }
        void setPlace(const string& newPlace) { namePlace = newPlace; }
};

#endif // TRAVEL_H