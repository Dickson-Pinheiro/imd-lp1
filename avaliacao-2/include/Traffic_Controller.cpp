#include "Traffic_Controller.h"
#include <iostream>

void TrafficController::registerCity(const std::string& name) {
    cities.push_back(new City(name));
}

void TrafficController::registerRoute(const std::string& startCityName, const std::string& endCityName, RouteType type, int distance) {
    City* startCity = nullptr;
    City* endCity = nullptr;
    for (City* city : cities) {
        if (city->getName() == startCityName) {
            startCity = city;
        }
        if (city->getName() == endCityName) {
            endCity = city;
        }
    }
    if (startCity && endCity) {
        routes.push_back(new Route(startCity, endCity, type, distance));
    } else {
        std::cerr << "One or both cities not found." << std::endl;
    }
}

void TrafficController::registerTransport(const std::string& name, TransportType type, int capacity, int speed, int distanceRest, int restTime, const std::string& currentCityName) {
    City* currentCity = nullptr;
    for (City* city : cities) {
        if (city->getName() == currentCityName) {
            currentCity = city;
            break;
        }
    }
    if (currentCity) {
        transports.push_back(new Transport(name, type, capacity, speed, distanceRest, restTime, currentCity));
    } else {
        std::cerr << "City not found." << std::endl;
    }
}

void TrafficController::registerPassenger(const std::string& name, const std::string& currentCityName) {
    City* currentCity = nullptr;
    for (City* city : cities) {
        if (city->getName() == currentCityName) {
            currentCity = city;
            break;
        }
    }
    if (currentCity) {
        passengers.push_back(new Passenger(name, currentCity));
    } else {
        std::cerr << "City not found." << std::endl;
    }
}

void TrafficController::startTravel(const std::string& transportName, const std::vector<std::string>& passengerNames, const std::string& startCityName, const std::string& endCityName) {
    Transport* transport = nullptr;
    City* startCity = nullptr;
    City* endCity = nullptr;
    std::vector<Passenger*> travelPassengers;

    for (Transport* t : transports) {
        if (t->getName() == transportName) {
            transport = t;
            break;
        }
    }

    for (City* city : cities) {
        if (city->getName() == startCityName) {
            startCity = city;
        }
        if (city->getName() == endCityName) {
            endCity = city;
        }
    }

    for (const std::string& passengerName : passengerNames) {
        for (Passenger* p : passengers) {
            if (p->getName() == passengerName) {
                travelPassengers.push_back(p);
                break;
            }
        }
    }

    if (transport && startCity && endCity && !travelPassengers.empty()) {
        travels.push_back(new Travel(transport, travelPassengers, startCity, endCity));
        travels.back()->startTravel();
    } else {
        std::cerr << "Error starting travel. Check transport, cities, and passengers." << std::endl;
    }
}

void TrafficController::advanceTravelHours(const std::string& transportName, int hours) {
    for (Travel* travel : travels) {
        if (travel->getTransport()->getName() == transportName) {
            travel->advanceHours(hours);
            return;
        }
    }
    std::cerr << "Travel not found for transport: " << transportName << std::endl;
}

void TrafficController::reportTravelStatus(const std::string& transportName) const {
    for (const Travel* travel : travels) {
        if (travel->getTransport()->getName() == transportName) {
            travel->reportStatus();
            return;
        }
    }
    std::cerr << "Travel not found for transport: " << transportName << std::endl;
}