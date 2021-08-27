// Sarah Gilliland

#include <iostream>
using namespace std;

int main() 
{
  long unsigned int army, foe = 0;

  while (cin >> army >> foe) 
  {
    if (army >= foe)
      cout << army - foe << '\n';
    else
      cout << foe - army << '\n';
	}
  return 0;
}