#include "solution.h"

#include <unordered_map>
#include <vector>
#include <iostream>

struct Intersection
{
    std::unordered_map<int, int> streetToCount;
};

std::vector<Schedule> solve(InputData& data)
{
    std::vector<Intersection> intersections(data.numberOfIntersection);
    for (const Car& car : data.cars)
    {
        for (const int streetId : car.streetsId)
        {
            intersections[data.streets[streetId].endIntersection].streetToCount[streetId]++;
        }
    }

    std::vector<Schedule> result;
    for (int i = 0; i < intersections.size(); ++i)
    {
        if (intersections[i].streetToCount.size() == 0)
            continue;
            
        Schedule s;
        s.id = i;

        int totalNumberOfCars = 0;
        const int secondsInCycle = intersections[i].streetToCount.size();
        for (const auto& streetToCount : intersections[i].streetToCount)
        {
            totalNumberOfCars += streetToCount.second;
        }
        for (const auto& streetToCount : intersections[i].streetToCount)
        {
            s.streetAndTime.push_back({data.streets[streetToCount.first].name, secondsInCycle * streetToCount.second / totalNumberOfCars + 1});
        }
        result.push_back(s);
    }
    return result;
}