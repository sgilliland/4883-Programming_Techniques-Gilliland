// Sarah Gilliland
// UVA 161 - Traffic Lights
// 4883 - Programming Techniques
// This program implements vectors and a brute-force approach
// to a problem looking at the similar timing of cycles for a
// given series of traffic lights.

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int seconds, interval = 0, tmp = 0;
    bool flag = true;
    bool allGreen, lightChange, notGreen;

    vector<int> scenarios;
    vector<int> lights;

    while (1)
    {
        allGreen = false;
        lightChange = false;

        if (tmp != 0)
        {
            // need for checking next int at end of loop
            scenarios.push_back(tmp);
        }

        cin >> interval;
        while (interval != 0)
        {
            // add light cycles to scenarios vector
            scenarios.push_back(interval);
            cin >> interval;
        }

        // Received help from David Hawkins here so this is his logic:
        /*************************************************************/

        // let the lights vector hold the color status:
        // 1 for green
        // 2 for orange
        // 3 for red
        lights.resize(scenarios.size());

        // all begin as green, so fill with 1s
        fill(lights.begin(), lights.end(), 1);

        // Brute force algorithm where time counts by seconds from 1 to 18000 (5 hours) to find a solution
        for (int time = 1; time <= 18000 && !allGreen; time++)
        {
            for (int i = 0; i < scenarios.size(); i++)
            {
                if (lights[i] == 1) // light is green, will turn orange
                {
                    if (time < scenarios[i])
                    {
                        if ((scenarios[i] - time) == 5)
                        {
                            lights[i] = 2;      // orange light
                            lightChange = true; // light has changed
                        }
                    }
                    else
                    {
                        if ((time % scenarios[i]) == (scenarios[i] - 5))
                        {
                            lights[i] = 2;      // orange light
                            lightChange = true; // light has changed
                        }
                    }
                }
                else if (lights[i] == 2) // light is orange, will turn red
                {
                    if (time <= scenarios[i])
                    {
                        if ((time - scenarios[i]) == 0)
                            lights[i] = 3; // red light
                    }
                    else
                    {
                        if ((time % scenarios[i]) == 0)
                            lights[i] = 3;
                    }
                }
                else if (lights[i] == 3) // light is red, will turn green
                {
                    if ((time % scenarios[i]) == 0)
                    {
                        lights[i] = 1; // green light
                    }
                }
            }

            notGreen = false;

            // Check if they are all green
            if (lightChange)
            {
                for (int j = 0; j < lights.size() && !notGreen; j++)
                {
                    // notGreen will be false if all are green
                    if (lights[j] != 1)
                        notGreen = true;
                }

                if (!notGreen)
                {
                    allGreen = true;
                    seconds = time;
                }
            }
        }
        /*************************************************************/

        if (allGreen)
        {
            // print hours (always 1 digit)
            cout << "0" << seconds / 3600;
            // print minutes
            // if minutes are only 1 digit
            if (seconds % 3600 / 60 < 10)
                cout << ":0" << seconds % 3600 / 60;
            else
                cout << ":" << seconds % 3600 / 60;
            // print seconds
            // if seconds are only 1 digit
            if (seconds % 60 < 10)
                cout << ":0" << seconds % 60 << '\n';
            else
                cout << ":" << seconds % 60 << '\n';
        }
        else
            cout << "Signals fail to synchronise in 5 hours\n";

        //clears the vector to make room for the next set
        scenarios.clear();
        lights.clear();

        //checks to see if the next value in the input is a 0. if so, quit the program.
        cin >> interval;
        if (interval == 0)
            break;
        else
            tmp = interval;
    }
    return 0;
}