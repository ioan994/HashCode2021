#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct Street
{
    int id;
    std::string name;
    int length;
    int startIntersection;
    int endIntersection;
};

struct Car
{
    std::vector<int> streetsId;
};

struct InputData
{
    int simulationDuration;
    int bonusPoints;
    int numberOfIntersection;
    std::unordered_map<std::string, int> streetNameToId;
    std::vector<Street> streets;
    std::vector<Car> cars;
};

InputData parse(const std::string& fileName);
