#include "input.hpp"
#include "parser.hpp"
#include "calculator.hpp"

// Output codes:
// 0 - nothing
// 1 - exit code

int inputString()
{   
    std::string inputString; 
    getline(std::cin, inputString);

    if (inputString == "quit")
    {
        return 1;
    }

    else if (inputString == "help")
    {
        std::string line;
        std::ifstream file ("handbook.txt");
        
        if (file.is_open())
        {
            while (getline (file,line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }

        else
        {
            std::cerr << "File handbook not found!" << std::endl;
        }
    }

    else 
    {   
        std::deque<std::string>elements;
        split(elements, inputString, " ");
        
        std::cout << calculator(elements) << std::endl;;
    }
    

    return 0;
}
