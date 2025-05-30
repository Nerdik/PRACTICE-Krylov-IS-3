// Point 4. Main task (realisation)

#include "queue.h"
#include "process_text.h"
#include <fstream>
#include <iostream>

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void processTextFile(const std::string& filename) {
    CharQueue non_digits;
    CharQueue digits;

    std::ifstream input(filename);
    if (!input.is_open())
    {
        throw std::runtime_error("Unable to open file " + filename);
    }

    char c;
    while (input.get(c))
    {
        if (isDigit(c))
        {
            digits.push(c);
        }
        else
        {
            non_digits.push(c);
        }
    }

    // Non-didgits output
    while (!non_digits.empty())
    {
        std::cout << non_digits.front();
        non_digits.pop();
    }

    // Digits output
    while (!digits.empty())
    {
        std::cout << digits.front();
        digits.pop();
    }

    std::cout << std::endl;
}
