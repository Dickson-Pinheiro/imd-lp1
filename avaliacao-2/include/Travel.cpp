#include "Travel.h"
#include <iostream>

Travel::Travel(Transport* transport, std::vector<Passenger*> passengers, City* startCity, City* endCity)
    : transport(transport), passengers(passengers), startCity(startCity), endCity(endCity), next(nullptr), hoursInTransit(0), inProgress(false) {}

void Travel::startTravel() {
    if (transport->getCurrentCity() == startCity) {
        inProgress = true;
        hoursInTransit = 0;
        std::cout << "Travel started from " << startCity->getName() << " to " << endCity->getName() << std::endl;
    } else {
        std::cout << "The transport is not in the start city." << std::endl;
    }
}

void Travel::advanceHours(int hours) {
    if (inProgress) {
        hoursInTransit += hours;
        int distanceCovered = hoursInTransit * transport->getSpeed();
        if (distanceCovered >= transport->getDistanceBetweenRests()) {
            transport->setCurrentRestTime(transport->getRestTime());
            std::cout << "Transport resting for " << transport->getRestTime() << " hours." << std::endl;
        }
        if (distanceCovered >= transport->getDistanceBetweenRests() + transport->getRestTime()) {
            transport->setCurrentCity(endCity);
            inProgress = false;
            std::cout << "Travel completed. Arrived at " << endCity->getName() << std::endl;
        }
    } else {
        std::cout << "The travel is not in progress." << std::endl;
    }
}

void Travel::reportStatus() const {
    std::cout << "Travel from " << startCity->getName() << " to " << endCity->getName() << std::endl;
    std::cout << "Hours in transit: " << hoursInTransit << std::endl;
    std::cout << "In progress: " << (inProgress ? "Yes" : "No") << std::endl;
}

bool Travel::isInProgress() const {
    return inProgress;
}