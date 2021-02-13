#include "calculator.hpp"

long double calculator(std::deque<std::string> elements)
{   
    std::deque<std::string> elements2;
    long double out;
    bool find = false;
    int priorety = 0;
    int temp = 0;
    int i = 0;

    while (elements.size() != 1) 
    {
        while (i < elements.size())
        {   try
            {
            if (priorety == 0 && i + 1)
            {
                if (elements[i + 1] == "^" && !find && i + 1 < elements.size())
                {
                    out = pow(std::stod(elements[i]), std::stod(elements[i + 2])); 
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
                if (elements[i + 1] == "*" && !find && i + 1 < elements.size())
                {
                    out = std::stod(elements[i]) * std::stod(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else if (elements[i + 1] == "/" && !find && i + 1 < elements.size())
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

            else if (priorety == 2)
            {
                if (elements[i + 1] == "+" && !find && i + 1 < elements.size())
                {
                    out = std::stod(elements[i]) + std::stod(elements[i + 2]); 
                    elements2.push_back(std::to_string(out));
                    find = true;
                    i += 2; 
                }

                else if (elements[i + 1] == "-" && !find && i + 1 < elements.size())
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
            catch(...)
            {
                throw "Syntax error";
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
    return std::stod(elements[0]);
}