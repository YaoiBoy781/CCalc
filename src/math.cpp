#include "math.hpp"

long double abs(long double a)
{
    if (a < 0)
    {
        return a - a * 2;
    }
    else
    {
        return a;
    }
}

long double pow(long double a, long double b)
{
    if (b < 0)
    {
        double temp = pow(a, abs(b));

        return 1/temp;
    }

    else
    {   
        double out;
        if (a < 0 || b < 0)
        {
            out = -1;
        }

        else
        {
            out = 1;
        }

        for (int i = 0; i < b; i++)
        {
            out *= a;
        }

        return out;
    }
}