#ifndef TRAVEL_H
#define TRAVEL_H

#include <vector>
#include "Transport.h"
#include "Passenger.h"
#include "City.h"

class Travel {
private:
    Transport* transport;
    std::vector<Passenger*> passengers;
    City* startCity;
    City* endCity;
    Travel* next;
    int hoursInTransit;
    bool inProgress;

public:
    Travel(Transport* transport, std::vector<Passenger*> passengers, City* startCity, City* endCity);
    Transport* getTransport() const { return transport; }
    void startTravel();
    void advanceHours(int hours);
    void reportStatus() const;
    bool isInProgress() const;
};;

#endif 