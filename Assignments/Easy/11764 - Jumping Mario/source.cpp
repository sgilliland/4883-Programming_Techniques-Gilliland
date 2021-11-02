// Sarah Gilliland
// UVA 11764 - Jumping Mario
// 4883 - Programming Techniques
#include <iostream>
using namespace std;
int main() 
{
  int testCases, numWalls, start, height, up, down, i = 0, j;
  cin >> testCases;
  while (i < testCases)
  {
    up = 0;
    down = 0;
    j = 0;

    cin >> numWalls;

    cin >> start; // read the height Mario starts on
    while (j < numWalls -1)
    {
      // compare the current height to the next height
      cin >> height;
      if (start > height)
        down++;
      else if (start < height)
        up++;
      start = height;
      j++;
    }
    printf("Case %d: %d %d\n",i+1,up,down);
    i++;
  }
  return 0;
} 