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
        int travelCost;
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
<<<<<<< HEAD
        void setPlace(const string& newPlace) { namePlace = newPlace; }
=======
        int getTravelCost(){return (travelCost = hotels[0].getTotalCost() + transports[0].get_cost());}
>>>>>>> f3326b47c053372425382a9ae35ef4598b7d4236
};
typedef Travel Service;
#endif // TRAVEL_H