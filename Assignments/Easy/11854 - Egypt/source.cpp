// Sarah Gilliland
// UVA 11854 - Egypt
// 4883 - Programming Techniques
#include <iostream>
#include <math.h>
using namespace std;
int main() {
  double s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  while(!(s1 == 0 && s2 == 0 && s3 == 0))
  {
    if (s2 == sqrt(pow(s1,2) + pow(s3,2)) || s1 == sqrt(pow(s2,2) + pow(s3,2)) || s3 == sqrt(pow(s1,2) + pow(s2,2)))
      cout << "right\n";
    else
      cout << "wrong\n";
    cin >> s1 >> s2 >> s3;
  }
  return 0;
} 