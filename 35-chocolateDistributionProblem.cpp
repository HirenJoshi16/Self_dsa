#include <bits/stdc++.h>
using namespace std;

// Displays element
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Elucidates chocolate distribution problem ~ O(nlogn) & O(1)
int distributeChocolate(int *A, int n, int students)
{
    int diff = 0;
    int minDiff = INT_MAX;
    sort(A, A + n);

    for (int i = 0; i + students - 1 < n; i++)
    {
        diff = A[i + students - 1] - A[i];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;
}

// Driver code
int main()
{
    int A[] = {7, 3, 2, 4, 9, 12, 56};
    int n = 7;
    printArray(A, n);
    
    if (int minDiff = distributeChocolate(A, n, 3))
    {
        cout << "Minimum difference is : " << minDiff;
    }
    else
    {
        cout << "something wrong";
    }
    return 0;
}