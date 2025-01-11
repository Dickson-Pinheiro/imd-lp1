#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "City.h"


class Passenger {
private:
    std::string name;
    City* currentCity;
public:
    Passenger(std::string name, City* currentCity);
    std::string getName();
    City* getCurrentCity();
    void setCurrentCity(City* city);
};

#endif