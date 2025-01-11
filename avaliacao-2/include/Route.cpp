#include "Route.h"
#include <string>
#include "City.h"

Route::Route(City* start, City* end, RouteType type, int distance)
    : startCity(start), endCity(end), routeType(type), distance(distance) {}

City* Route::getStartCity() const {
    return startCity;
}

City* Route::getEndCity() const {
    return endCity;
}

RouteType Route::getRouteType() const {
    return routeType;
}

int Route::getDistance() const {
    return distance;
}

void Route::setStartCity(City* start) {
    startCity = start;
}

void Route::setEndCity(City* end) {
    endCity = end;
}

void Route::setRouteType(RouteType type) {
    routeType = type;
}

void Route::setDistance(int distance) {
    this->distance = distance;
}