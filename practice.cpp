// Variant 3

#include <iostream>
#include <stdexcept>
#include "process_text.h"

// Main task function
void taskLaunch()
{
    const char* filename = "text.txt";
    std::cout << "Processing file " << filename << ":" << std::endl;
    processTextFile(filename);
}

int main()
{
    try {
        taskLaunch();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Warning! Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
