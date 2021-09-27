// Sarah Gilliland
// UVA 900 - Brick Wall Patterns
#include <bits/stdc++.h>
using namespace std;

// This function is modified from the code given by
// Code_Mech's Space Optimized Method of Fibonacci Sequence
// from https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
void fibFast(unsigned long n)
{
    unsigned long a = 0, b = 1, c, i;
    if (n == 0)
        cout << a << '\n';
    for (i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << b << '\n';
    return;
}

int main()
{
    unsigned long n;
    cin >> n;
    while (n != 0)
    {
        fibFast(n);
        cin >> n;
    }

    return 0;
}