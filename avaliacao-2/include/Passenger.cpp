#include "Passenger.h"
#include <string>
#include "City.h"

Passenger::Passenger(std::string name, City* currentCity)
    : name(name), currentCity(currentCity) {}

std::string Passenger::getName() {
    return name;
}

City* Passenger::getCurrentCity() {
    return currentCity;
}

void Passenger::setCurrentCity(City* city) {
    currentCity = city;
}