// Sarah Gilliland
// 4883 - Programming Techniques
// UVA 108 - Maximum Sum
/********************************************
 *  Program to use dynamic programming to find 
 *  maximum sum subarray in a given 2D array.
 *  Code for Kadane's implementation by 
 *  rathbhupendra from Geeks for Geeks.
 * https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
 ********************************************/
#include <bits/stdc++.h>
using namespace std;
 
// Implementation of Kadane's algorithm for 1D array
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i, local_start = 0;;
 
    // check for negative values edge case
    *finish = -1;
 
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    // at-least one non-negative number
    if (*finish != -1)
        return maxSum;
 
    // special case: all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;
 
    // find max element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
 

// The function that finds maximum sum rectangle in M[][]
void find2DMaxSum(int** M, int N)
{
    // Variables to store the final output
    int maxSum = INT_MIN;
 
    int left, right, i;
    int temp[N], sum, start, finish;
 
    // Set the left column
    for (left = 0; left < N; ++left) 
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));
 
        // Set the right column for the left
        // column set by outer loop
        for (right = left; right < N; ++right) 
        {
 
            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < N; ++i)
                temp[i] += M[i][right];
 
            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, &start, &finish, N);
 
            // update maxSum if there is a new maximum sum
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << maxSum << endl;
}

int main()
{
  int N, num;
  while(cin >> N)
  {
    int** Rectangle = new int*[N];
    for(int i = 0; i < N; i++)
    { Rectangle[i] = new int[N]; }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> num;
        Rectangle[i][j] = num;
      }
    }
    find2DMaxSum(Rectangle, N);
  }
  
  return 0;
}