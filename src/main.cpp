#include "input.hpp"

int main()
{   
    int output;

    std::cout << "CCalc version 1.1" << std::endl;
    std::cout << "help - handbook" << std::endl;

    while(true)
    {   
        std::cout << ">>";

        output = inputString();

        if (output == 1)
        {
            return 1;
        }
    }
}