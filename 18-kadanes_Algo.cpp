// Program to implement kadanes algorithm by finding maximum sum contiguos subarray
#include <bits/stdc++.h>
using namespace std;

// Display elements
void traversel(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Kadane's Algorithm ~ O(n) & O(1)
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

// Driver code
int main(){
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(A)/sizeof(A[0]);
    traversel(A, n);
    cout<<endl;
    cout<<"Maximum contiguos sum of sub Array is : "<<maxSumsubArray(A, n);
    return 0;
}