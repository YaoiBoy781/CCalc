#include <iostream>
#include <vector>

using namespace std;

void med(string str, char sep)
{
    vector<double> list;
    string temp;
    str = str + sep;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != sep)
        {
            temp = temp + str[i];
        }

        else
        {
            if (temp.size() != 0)
            {
                list.push_back(stof(temp));
            }

            temp = "";
        }
    }

    cout << endl;;

    // Sweep start
    double min = list[0],max = list[0];

    for(double i : list)
    {
        if (min > i)
        {
            min = i;
        }

        if (max < i)
        {
            max = i;
        }
    }

    cout << "sweep:" << max - min << endl;
    // Sweep end

    // Fashion start
    int count = 0;
    double mas[list.size()];
    bool have = false;

    for(int i = 0; i < list.size(); i++)
    {
        for(double z : list)
        {
            if(list[i] == z)
            {
                for(double j : mas)
                {
                    if (j == z)
                    {
                        have = true;
                        break;
                    }

                    else
                    {
                        have = false;
                    }

                }

                if (have)
                {
                    count++;
                }

            }
        }
        if (count > 1)
        {
            cout << "number " << list[i] << " - " << count << " times" << endl;
        }
        mas[i] = list[i];
        count = 0;
    }
    // Fashion end

    // Median Start
    for(int i = 0; i < list.size() - 1;i++)
    {
        for(int j = 0; j < list.size() - 1;j++)
        {
            double f = 0;
            if(list[j] >= list[j + 1])
            {
                f = list[j + 1];
                list[j + 1]=list[j];
                list[j] = f;
            }
        }
    }

    if((list.size() - 1) % 2 == 0)
    {
        cout << "median:" << ( list[(list.size() - 1) / 2] )<< endl;
    }

    else
    {
        cout << "median:" << ( list[(list.size() / 2) - 1] + list[(list.size() / 2)] ) / 2.f << endl;
    }
    // Median end

    // Average start
    double num;

    for(double i : list)
    {
        num += i;
    }

    cout << "average:" << num / list. size() << endl;

    // Average end

    cout << endl;
}


// Input func
int input()
{
    string str;

    getline(cin, str);

    if (str == "help")
    {
        cout << "exit - quit from program" << endl;
        cout << "$sfma - math sweep-fashion-median-average" << endl;
        return 0;
    }

    else if (str == "exit")
    {
        return -1;
    }

    else if (str == "$sfma")
    {
        char sep;


        cout << "enter separator character:";
        cin.get(sep);

        cin.ignore();

        cout << "enter a series of numbers:";
        getline(cin, str);

        med(str, sep);

    }

    return 0;
}

int main()
{
    while(true)
    {
        cout << ":    ";

        if (input() == -1) // If break code
        {
            break;
        }
    }

    return 0;
}