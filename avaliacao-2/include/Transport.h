#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include "City.h"

enum class TransportType
{
    Terrestre,
    Aquatico,
    Aereo
};

class Transport
{
private:
    std::string name;
    TransportType type;
    int passengerCapacity;
    int speed;
    int distanceBetweenRests;
    int restTime;
    int currentRestTime;
    City *currentCity;

public:
    Transport(const std::string &name, TransportType type, int capacity, int speed, int distanceRest, int restTime, City *city);
    std::string getName() const;
    TransportType getType() const;
    int getPassengerCapacity() const;
    int getSpeed() const;
    int getDistanceBetweenRests() const;
    int getRestTime() const;
    int getCurrentRestTime() const;
    City *getCurrentCity() const;
    void setName(const std::string &name);
    void setType(TransportType type);
    void setPassengerCapacity(int capacity);
    void setSpeed(int speed);
    void setDistanceBetweenRests(int distanceRest);
    void setRestTime(int restTime);
    void setCurrentCity(City *city);
    void setCurrentRestTime(int restTime);
};

#endif