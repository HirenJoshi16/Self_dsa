// Most Important Question, its also called Kadane's Algorithm ~ T.C - O(n), S.C - O(1)
#include <iostream>
using namespace std;

// Shows the elements
void printArray(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}

//Finds maximum sum of subarray - efficient approach using kadane's algorithm
int maxSumsubArray(int *A, int n)
{
    int curr = 0;       // Stores current value of A[]
    int maxTillnow = 0; // Stores max value of A[], updated by current if current is greater then it

    for (int i = 0; i <= n - 1; i++)
    {
        curr += A[i]; // Adding elements to current in each iteration
        if (curr < 0) // If current value is negative then discard the value and set current to zero
        {
            curr = 0;
        }
        if (curr > maxTillnow) // If current value is greater then update maximum value by current
        {
            maxTillnow = curr;
        }
    }
    return maxTillnow;
}

int main()
{
    int A[] = {5, -4, -2, 6, -1};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A, n);
    cout<<endl;
    cout<<"Maximum contiguos sum of sub Array is : "<<maxSumsubArray(A, n);
    return 0;
}