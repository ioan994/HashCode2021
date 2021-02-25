#pragma once

#include <string>
#include <vector>
#include <utility>

struct Schedule
{
    int id;
    std::vector<std::pair<std::string, int>> streetAndTime;
};

void format(const std::vector<Schedule>& schedules, const std::string& fileName);