#include "formatter.h"

#include <iostream>
#include <fstream>

void format(const std::vector<Schedule>& schedules, const std::string& fileName)
{
    std::ofstream out(fileName);

    int A = schedules.size();
    out << A << std::endl;

    for (const auto& schedule : schedules)
    {
        const auto& i = schedule.id;
        out << i << std::endl;

        int Ei = schedule.streetAndTime.size();
        out << Ei << std::endl;

        for (const auto& streetAndTime : schedule.streetAndTime)
        {
            const auto& name = streetAndTime.first;
            const auto& T = streetAndTime.second;

            out << name << " " << T << std::endl;
        }
    }

    out.close();
}
