#include "Transport.h"

Transport::Transport(const std::string& name, TransportType type, int capacity, int speed, int distanceRest, int restTime, City* city)
    : name(name), type(type), passengerCapacity(capacity), speed(speed), distanceBetweenRests(distanceRest), restTime(restTime), currentRestTime(0), currentCity(city) {}

std::string Transport::getName() const {
    return this->name;
}

TransportType Transport::getType() const {
    return type;
}

int Transport::getPassengerCapacity() const {
    return passengerCapacity;
}

int Transport::getSpeed() const {
    return speed;
}

int Transport::getDistanceBetweenRests() const {
    return distanceBetweenRests;
}

int Transport::getRestTime() const {
    return restTime;
}

int Transport::getCurrentRestTime() const {
    return currentRestTime;
}

City* Transport::getCurrentCity() const {
    return currentCity;
}

void Transport::setName(const std::string& name) {
    this->name = name;
}

void Transport::setType(TransportType type) {
    this->type = type;
}

void Transport::setPassengerCapacity(int capacity) {
    this->passengerCapacity = capacity;
}

void Transport::setSpeed(int speed) {
    this->speed = speed;
}

void Transport::setDistanceBetweenRests(int distanceRest) {
    this->distanceBetweenRests = distanceRest;
}

void Transport::setRestTime(int restTime) {
    this->restTime = restTime;
}

void Transport::setCurrentCity(City* city) {
    this->currentCity = city;
}

void Transport::setCurrentRestTime(int restTime) {
    this->currentRestTime = restTime;
}