// Program to find non subarray if sum equal to zero
// Standerdly subarray is a contiguous part of array
#include <iostream>
#include <unordered_set>
using namespace std;

// Optimal Approach using hashing to find subarray sum equal to zero ~ T.C - O(n), S.C - O(n)
bool findSubsum(int *A, int n)
{
    unordered_set<int> sumSet;

    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}

// Driver code
int main()
{
    // int A[] = {-3, 1, 2, 4, 6};
    // int A[] = {1, 4, -2, -2, 0, -4, 3};
    int A[] = {4, 7, -6, -10, 6, 6, 3};
    // int A[] = {1, 0, -6, -10, 0};
    // int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    findSubsum(A, n);

    return 0;
}