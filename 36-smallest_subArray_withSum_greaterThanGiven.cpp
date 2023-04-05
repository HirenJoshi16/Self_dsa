// Program to find smallest subArray with sum greater than given value
#include <bits/stdc++.h>
using namespace std;

// Look out the naive approach of it

// Optimal Approach to find ~ T.C - O(n), S.C - O(1)
int findSmallestsub(int *A, int n, int x){
    int min_len = n+1;

    int curr_sum = 0;
    int start, end;
    start = end = 0;

    while(end < n){

        while(curr_sum <= x && end < n){
            curr_sum += A[end++];
        }

        while(curr_sum > x && start < n){
            if(min_len > end-start){
                min_len = min(end-start, min_len);
            }
            curr_sum -= A[start++];
        }
    }
    return min_len;
} 

// GeekForGeek code
// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSum(int arr[], int n, int x)
{
    //  Initialize length of smallest subarray as n+1
     int min_len = n + 1;
 
     // Pick every element as starting point
     for (int start=0; start<n; start++)
     {
          // Initialize sum starting with current start
          int curr_sum = arr[start];
 
          // If first element itself is greater
          if (curr_sum > x) return 1;
 
          // Try different ending points for current start
          for (int end=start+1; end<n; end++)
          {
              // add last element to current sum
              curr_sum += arr[end];
 
              // If sum becomes more than x and length of
              // this subarray is smaller than current smallest
              // length, update the smallest length (or result)
              if (curr_sum > x && (end - start + 1) < min_len)
                 min_len = (end - start + 1);
          }
     }
     return min_len;
}

// Driver code
int main()
{
    // int A[] = {-3, 1, 2, 4, 6};
    // int A[] = {1, 4, -2, -2, 0, -4, 3};
    // int A[] = {1, 4, 45, 6, 10, 19};
    int A[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int x = 280;
    // int A[] = {1, 0, -6, -10, 0};
    // int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    cout<<findSmallestsub(A, n, x);

    return 0;
}