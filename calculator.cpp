#include "calculator.hpp"
#include <iterator>
#include <ostream>

float calculator(std::deque<std::string> elements)
{   
    std::deque<std::string> elements2;
    float out;
    bool find = false;
    bool plusSub = false;
    int temp;

    while (elements.size() != 1) 
    {
        for (int i = 0; i < elements.size(); i++)
        {
            if (!plusSub)
            {
                if (elements[i + 1] == "*" && !find)
                {
                    out = std::stof(elements[i]) * std::stof(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else if (elements[i + 1] == "/" && !find)
                {
                    out = std::stof(elements[i]) / std::stof(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else
                {
                    elements2.push_back(elements[i]);
                }

                for (auto i : elements)
                {
                    if (i == "*" || i == "/")
                    {
                        temp++;
                    }
                }

                if (temp == 0)
                {
                    plusSub = true;
                }
                temp = 0;
            }

            else
            {
                if (elements[i + 1] == "+" && !find)
                {
                    out = std::stof(elements[i]) + std::stof(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else if (elements[i + 1] == "-" && !find)
                {
                    out = std::stof(elements[i]) - std::stof(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else
                {
                    elements2.push_back(elements[i]);
                }
            }
            
        }
        elements.clear();
        elements.swap(elements2);

        find = false;

    }
    return std::stof(elements[0]);
}

/*
void calculator(std::deque<std::string> elements)
{   
    std::deque<std::string>elements2;  
    bool find = false;
    bool plusSub = false;
    double out;

    while(elements.size() != 1)
    {
        for (int i = 0; i < elements.size(); i++)
        {   
            if (!plusSub)
            {
                if (elements[i + 1] == "*" && !find)
                {
                    out = std::stod(elements[i]) * std::stod(elements[i + 2]);
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2;
                }

                else if (elements[i + 1] == "/" && !find)
                {
                    out = std::stod(elements[i]) / std::stod(elements[i + 2]);
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2;
                }

                else
                {
                    elements2.push_back(elements[i]);
                }
            }

            else
            {
                if (elements[i + 1] == "+" && !find)
                {
                    out = std::stod(elements[i]) + std::stod(elements[i + 2]);
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2;
                }

                else if (elements[i + 1] == "-" && !find)
                {
                    out = std::stod(elements[i]) - std::stod(elements[i + 2]);
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2;
                }

                else
                {
                    elements2.push_back(elements[i]);
                }
            }
    
        }
        elements.clear();
        elements.swap(elements2);

        if (!find)
        {   
            
            std::cout << std::endl;
            for (auto i : elements)
            {
                std::cout << i;
            }
            std::cout << std::endl;
            
            plusSub = true;
        }

        find = false;
    }

    for (auto i : elements)
    {
        std::cout << i << std::endl;
    }
}
*/