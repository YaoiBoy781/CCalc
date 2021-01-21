#include "parser.hpp"

void split(std::deque<std::string> &elements, std::string &inputString, const char *sep)
{
    char *temp = strdup(inputString.c_str());      
    char *word = strtok(temp, sep);       
    while(word != NULL)
    {
        elements.push_back(word);
        word = strtok(NULL, sep);        
    }
    
    free(temp); 
}
