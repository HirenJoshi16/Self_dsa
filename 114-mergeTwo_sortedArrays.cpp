#include <bits/stdc++.h>
using namespace std;

// Prints elements
void printElements(map<int, int> mp){
    for(auto j: mp){
        for(int i=0; i<j.second;i++)cout<<j.first<<" ";
    }
}

// Merges two sorted array
void mergeArrays(int *A, int *B, int n, int m){
    map <int, int> freqCount;

    for(int i=0; i<n; i++){
        freqCount[A[i]]++;
    }
    for(int i=0; i<m; i++){
        freqCount[B[i]]++;
    }
    printElements(freqCount);
}

// Driver code
int main()
{
    int A[] = {1, 2, 3, 4, 5, 5};
    int B[] = {3, 3, 5, 10, 16, 20};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    mergeArrays(A, B, n, m);
    return 0;
}