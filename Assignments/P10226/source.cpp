// Sarah Gilliland
// UVA 10226 - Hardwood Trees
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

map<string, int> mp;

// Function to return if the tree is already in the map or not
bool inMap(string tree)
{
    auto it = mp.find(tree);
    if (it->second != 0) // if tree is in the map, update it and return true
    {
        it->second++;
        return true;
    }
    return false; // else, return false
}

// Function to print the contents of the map for testing purposes
void printMap(double count)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << ' ' << fixed << setprecision(4) 
            << (double)(itr->second) * 100 / count << '\n';
    }
}

int main()
{
    int testCases, i = 0;
    double counter = 0.0;
    string tree;
    cin >> testCases;
    getline(cin, tree); // get the rest of the line for whatever reason
    getline(cin, tree); // get the blank line

    while (i < testCases)
    {
        getline(cin, tree); // Get tree name

        while (tree != "") // if not a blank line (which ends the case)
        {
            counter++;
            if (!(inMap(tree))) // if the first instance of the tree
            {
                mp.insert({tree, 1}); // insert to map with counter of 1
            } 

            getline(cin, tree); // get the next tree name
        }

        printMap(counter);
        if (i != testCases - 1)
            cout << '\n';
        i++;
        mp.clear();
        counter = 0;
    }
    return 0;
}