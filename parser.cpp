#include "parser.hpp"

bool syntaxCheck(std::string &inputString)
{   
  std::string ops = "+-*/^.";
    bool find;

    if (inputString.size() == 0)
    {
        return true;
    }

    for(char symbol : inputString)
    {
        if (!isalnum(symbol) || isalpha(symbol))
        {
            for (char op : ops)
            {
                if (op == symbol)
                {   
                    find = true;
                    break;
                }

                else
                {
                    find = false;

                }

            }
            if (!find)
            {   
                std::cerr << "Symbol " << symbol << " not found!" << std::endl;
                return true;
            }
        }
    }

    return false;
}

void split (std::deque <std::string> &elements, std::string &inputString)
{
    bool find = false;
    char *op;
    char symbol;
    std::string temp;

    for (int index = 0; index < inputString.size(); index++)
    {   
        symbol = inputString[index];

        switch (symbol)
        {
            case operations::plus:
                find = true;
                op = "+";
                break;

            case operations::minus:
                if (inputString[index] == *"-" && inputString[index + 1] == *"-")
                {
                    op = "-";
                    find = true;
                }

                else if (!isalnum(inputString[index - 1]) && inputString[index] == *"-" && isalnum(inputString[index + 1]))
                {
                    temp = "-" + temp;
                    op = "";
                }

                else
                {
                    op = "-";
                    find = true;
                }

                break;

            case operations::multiply:
                find = true;
                op = "*";
                break;

            case operations::division:
                find = true;
                op = "/";
                break;
           
            case operations::power:
                find = true;
                op = "^";
                break;

            case operations::bracket_right:
                find = true;
                op = ")";
                break;

            case operations::bracket_left:
                find = true;
                op = "(";
                break;

            default:
                temp += symbol;
                op = "";
                break;
        }

        if (find)
        {   
            if (temp != "" && op != "")
            {
                elements.push_back(temp);
                temp = "";
            }

            if (op != "")
            {
                elements.push_back(op);
            }

            op = "";
            find = false;
        }

        else if (index == inputString.size() - 1)
        {
            elements.push_back(temp);
            temp = "";
        }
    }

}