#include <iostream>
#include <City.h>
#include <Transport.h>
#include <Passenger.h>
#include <Route.h>
#include <Travel.h>
#include <Traffic_Controller.h>

int main() {
    //City city = City("City 1");
    //City city2 = City("City 2");
    //Route route = Route(&city, &city2, RouteType::Terrestre, 100);
    //Transport transport = Transport("Transport 1", TransportType::Terrestre, 10, 100, 100, 10, &city);
    //Passenger passenger = Passenger("Passenger 1", &city);
    //Travel travel = Travel(&transport, {&passenger}, &city, &city2);
    TrafficController trafficController = TrafficController();
    trafficController.registerCity("City 1");
    trafficController.registerCity("City 2");
    trafficController.registerRoute("City 1", "City 2", RouteType::Terrestre, 100);
    trafficController.registerTransport("Transport 1", TransportType::Terrestre, 10, 100, 100, 10, "City 1");
    trafficController.registerPassenger("Passenger 1", "City 1");
    trafficController.startTravel("Transport 1", {"Passenger 1"}, "City 1", "City 2");
    trafficController.advanceTravelHours("Transport 1", 10);
    trafficController.reportTravelStatus("Transport 1");
    return 0;
}