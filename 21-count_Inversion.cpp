// Find Count Inversion efficiently
// Check this Approaches - Binary index tree, AVL tree, Merge sort, using Mapset, here best one is BIT it takes O(n) T.C
#include <bits/stdc++.h>
using namespace std;

// Bad(Naive) Apprcoach - Finds count inversion ~ T.C - O(n^2), S.C - O(1)
int countInversion(int *A, int n)
{
    int invCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
                invCount++;
        }
    }
    return invCount;
}

// Driver code
int main()
{
    int A[] = {2, 4, 1, 3, 5};
    int n = sizeof(A) / sizeof(A[0]);
    cout << " Number of inversions are " << countInversion(A, n);
    return 0;
}