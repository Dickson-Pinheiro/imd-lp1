#include <iostream>
#include <vector>
#include <string>
#include "Traffic_Controller.h"

void displayMenu()
{
    std::cout << "Menu:\n";
    std::cout << "1. Cadastrar Cidade\n";
    std::cout << "2. Cadastrar Trajeto\n";
    std::cout << "3. Cadastrar Transporte\n";
    std::cout << "4. Cadastrar Passageiro\n";
    std::cout << "5. Iniciar Viagem\n";
    std::cout << "6. Avançar Horas de Viagem\n";
    std::cout << "7. Relatar Status da Viagem\n";
    std::cout << "8. Sair\n";
    std::cout << "Escolha uma opção: ";
}

TransportType getTransportType(int transportTypeIndex)
{
    switch (transportTypeIndex)
    {
    case 0:
        return TransportType::Terrestre;
    case 1:
        return TransportType::Aquatico;
    case 2:
        return TransportType::Aereo;
    default:
        return TransportType::Terrestre;
    }
}

RouteType getRouteType(int routeTypeIndex)
{
    switch (routeTypeIndex)
    {
    case 0:
        return RouteType::Terrestre;
    case 1:
        return RouteType::Aquatico;
    case 2:
        return RouteType::Aereo;
    default:
        return RouteType::Terrestre;
    }
}

void handleMenuOption(TrafficController &trafficController, int option)
{
    std::string name, startCity, endCity, transportName, passengerName;
    int distance, capacity, transportTypeIndex, routeTypeIndex, speed, distanceRest, restTime, hours;
    TransportType transportType;
    RouteType routeType;
    std::vector<std::string> passengerNames;

    switch (option)
    {
    case 1:
        std::cout << "Nome da Cidade: ";
        std::cin >> name;
        trafficController.registerCity(name);
        break;
    case 2:
        std::cout << "Cidade de Origem: ";
        std::cin >> startCity;
        std::cout << "Cidade de Destino: ";
        std::cin >> endCity;
        std::cout << "Tipo de Trajeto (0: Terrestre, 1: Aquatico, 2: Aereo): ";
        std::cin >> routeTypeIndex;
        std::cout << "Distância: ";
        std::cin >> distance;
        routeType = getRouteType(routeTypeIndex);
        trafficController.registerRoute(startCity, endCity, routeType, distance);
        break;
    case 3:
        std::cout << "Nome do Transporte: ";
        std::cin >> name;
        std::cout << "Tipo de Transporte (0: Terrestre, 1: Aquatico, 2. Aereo): ";
        std::cin >> transportTypeIndex;
        std::cout << "Capacidade: ";
        std::cin >> capacity;
        std::cout << "Velocidade: ";
        std::cin >> speed;
        std::cout << "Distância de Descanso: ";
        std::cin >> distanceRest;
        std::cout << "Tempo de Descanso: ";
        std::cin >> restTime;
        std::cout << "Cidade Atual: ";
        std::cin >> startCity;
        transportType = getTransportType(transportTypeIndex);
        trafficController.registerTransport(name, transportType, capacity, speed, distanceRest, restTime, startCity);
        break;
    case 4:
        std::cout << "Nome do Passageiro: ";
        std::cin >> name;
        std::cout << "Cidade Atual: ";
        std::cin >> startCity;
        trafficController.registerPassenger(name, startCity);
        break;
    case 5:
        std::cout << "Nome do Transporte: ";
        std::cin >> transportName;
        std::cout << "Cidade de Origem: ";
        std::cin >> startCity;
        std::cout << "Cidade de Destino: ";
        std::cin >> endCity;
        std::cout << "Nomes dos Passageiros (separados por espaço, termine com 'end'): ";
        while (std::cin >> passengerName && passengerName != "end")
        {
            passengerNames.push_back(passengerName);
        }
        trafficController.startTravel(transportName, passengerNames, startCity, endCity);
        break;
    case 6:
        std::cout << "Nome do Transporte: ";
        std::cin >> transportName;
        std::cout << "Horas a Avançar: ";
        std::cin >> hours;
        trafficController.advanceTravelHours(transportName, hours);
        break;
    case 7:
        std::cout << "Nome do Transporte: ";
        std::cin >> transportName;
        trafficController.reportTravelStatus(transportName);
        break;
    case 8:
        std::cout << "Saindo...\n";
        exit(0);
    default:
        std::cout << "Opção inválida!\n";
    }
}

int main()
{
    TrafficController trafficController;
    int option;

    while (true)
    {
        displayMenu();
        std::cin >> option;
        if (option == 8)
        {
            break;
        }
        handleMenuOption(trafficController, option);
    }

    return 0;
}