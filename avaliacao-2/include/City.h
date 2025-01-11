#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>

class City {
private:
    std::string name;
    static std::vector<City> cities;

public:
    City(const std::string& cityName);
    std::string getName() const;
    void setName(const std::string& cityName);

    static std::vector<City> getCities();
};

#endif