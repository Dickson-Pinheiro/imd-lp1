#ifndef TRAFFIC_CONTROLLER_H
#define TRAFFIC_CONTROLLER_H

#include <vector>
#include <string>
#include "City.h"
#include "Route.h"
#include "Transport.h"
#include "Passenger.h"
#include "Travel.h"

class TrafficController
{
private:
    std::vector<City *> cities;
    std::vector<Route *> routes;
    std::vector<Transport *> transports;
    std::vector<Passenger *> passengers;
    std::vector<Travel *> travels;

public:
    void registerCity(const std::string &name);
    void registerRoute(const std::string &startCityName, const std::string &endCityName, RouteType type, int distance);
    void registerTransport(const std::string &name, TransportType type, int capacity, int speed, int distanceRest, int restTime, const std::string &currentCityName);
    void registerPassenger(const std::string &name, const std::string &currentCityName);
    void startTravel(const std::string &transportName, const std::vector<std::string> &passengerNames, const std::string &startCityName, const std::string &endCityName);
    void advanceTravelHours(const std::string &transportName, int hours);
    void reportTravelStatus(const std::string &transportName) const;
};

#endif