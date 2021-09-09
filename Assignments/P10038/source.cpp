// Sarah Gilliland
// UVA 10038 - Jolly Jumper
#include <iostream>
#include <math.h>

using namespace std;

// Function to check if all values in index 1...n of an array, a, are 1
// Returns true if so, and false if not
bool checkJolly(int a[3000], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] != 1)
            return false;
    }
    return true;
}

int main()
{
    int n, num1, num2, result;
    int a[3000];

    while (cin >> n)
    {
        cin >> num1;
        if (n > 1) // more than 1 number in the sequence
        {
            for (int i = 0; i < n - 1; i++)
            {
                cin >> num2;
                result = abs(num1 - num2);
                if (result < n)
                    a[result] = 1;
                num1 = num2; // make the old num2 the new num1
            }

            if (checkJolly(a, n))
                cout << "Jolly\n";
            else
                cout << "Not jolly\n";
        }
        else // only one number, so it is automatically jolly
            cout << "Jolly\n";

        for (int i = 0; i < n; i++)
        {
            a[i] = 0; // reset all elements of array to zero
        }
    }
    return 0;
}