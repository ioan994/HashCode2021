#include "parse.h"
#include "formatter.h"

#include "solution.h"

#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    const char* inputFile = argc > 1 ? argv[1] : "input/a.txt";
    const char* outputFile = argc > 2 ? argv[2] : "output.txt"; 

    std::cout << "\n input " << inputFile << " output: " << outputFile << "\n";
    InputData data = parse(inputFile);
    const auto solution = solve(data);
    format(solution, outputFile);
    return 0;
} 