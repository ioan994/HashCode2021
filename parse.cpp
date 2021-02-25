#include "parse.h"

#include <iostream>
#include <fstream>

InputData parse(const std::string& fileName)
{
    std::ifstream input(fileName);

    if (!input)
    {
        std::cerr << "Could not open the file!" << std::endl;
        return {};
    }

    InputData data;

    int D, I, S, V, F;
    input >> D >> I >> S >> V >> F;

    data.simulationDuration = D;
    data.numberOfIntersection = I;
    data.bonusPoints = F;

    for (int i = 0; i < S; i++)
    {
        int B, E;
        input >> B >> E;

        std::string name;
        input >> name;

        int L;
        input >> L;

        Street street;
        street.id = i;
        street.name = name;
        street.length = L;
        street.startIntersection = B;
        street.endIntersection = E;

        data.streets.push_back(street);

        data.streetNameToId[street.name] = street.id;
    }

    for (int i = 0; i < V; i++)
    {
        int P;
        input >> P;

        Car car;

        for (int p = 0; p < P; p++)
        {
            std::string name;
            input >> name;

            int streetId = data.streetNameToId[name];

            car.streetsId.push_back(streetId);
        }

        data.cars.push_back(car);
    }

    return data;
}
