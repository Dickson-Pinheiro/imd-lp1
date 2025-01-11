#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include "City.h"

enum RouteType {
    Aquatico,
    Terrestre
};

class Route {
private:
    City* startCity;
    City* endCity;
    RouteType routeType;
    int distance;

public:
    Route(City* start, City* end, RouteType type, int distance);
    
    City* getStartCity() const;
    City* getEndCity() const;
    RouteType getRouteType() const;
    int getDistance() const;


    void setStartCity(City* start);
    void setEndCity(City* end);
    void setRouteType(RouteType type);
    void setDistance(int distance);

};

#endif