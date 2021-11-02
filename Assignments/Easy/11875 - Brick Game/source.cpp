// Sarah Gilliland
// UVA 11875 - Brick Game
// 4883 - Programming Techniques
#include <iostream>
using namespace std;

int main() {
  int t, n, age, temp;
  cin >> t;

  // read in all ages for each test case
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    int ages[n]; // array named ages
    for (int j = 0; j < n; j++)
    {
      cin >> age;
      ages[j] = age;
    }

    // simple sort algorithm: ascending
    for(int s = 0; s < n; s++)
    {		
      for(int t = s + 1; t < n; t++)
      {
        if(ages[s] > ages[t])
        {
          temp = ages[s];
          ages[s] = ages[t];
          ages[t] = temp;
        }
      }
    }
    // print the age in the center of the array
    printf("Case %d: %d\n", i+1, ages[n/2]);
  }
  return 0;
} 