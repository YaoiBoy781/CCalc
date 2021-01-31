#include "calculator.hpp"

float calculator(std::deque<std::string> elements)
{   
    std::deque<std::string> elements2;
    float out;
    bool find = false;
    int priorety = 0;
    int temp = 0;
    int i = 0;

    while (elements.size() != 1) 
    {
        while (i < elements.size())
        {   
            if (priorety == 0)
            {
                if (elements[i + 1] == "^" && !find)
                {
                    out = pow(std::stof(elements[i]), std::stof(elements[i + 2])); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else
                {
                    elements2.push_back(elements[i]);
                }
            }

            else if (priorety == 1)
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
            }

            else if (priorety == 2)
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
            i++;
        }
        
        for (auto i : elements)
        {
            if (priorety == 0)
            {
                if (i == "^")
                {
                    temp++;
                }
            }

            else if (priorety == 1)
            {
                if (i == "*" || i == "/")
                {
                    temp++;
                }
            }

            else if (priorety == 2)
            {
                if (i == "+" || i == "-")
                {
                    temp++;
                }
            }
        }

        if (temp == 0)
        {
            priorety++;
        }

        elements.clear();
        elements.swap(elements2);
    
        find = false;
        temp = 0;
        i = 0;

    }
    return std::stof(elements[0]);
}

