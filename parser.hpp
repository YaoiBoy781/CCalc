#include <iostream>
#include <string>
#include <deque>

enum operations
{
    plus = *"+",
    minus = *"-",
    multiply = *"*",
    division = *"/",
    power = *"^",
    bracket_right = *")",
    bracket_left = *"("
};

bool syntaxCheck(std::string &inputString);
void split (std::deque <std::string> &elements, std::string &inputString);