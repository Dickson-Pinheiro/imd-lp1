#include "City.h"

std::vector<City> City::cities;

City::City(const std::string& cityName) : name(cityName) {
    City::cities.push_back(*this);
}

std::string City::getName() const {
    return name;
}

void City::setName(const std::string& cityName) {
    name = cityName;
}

std::vector<City> City::getCities() {
    return cities;
}