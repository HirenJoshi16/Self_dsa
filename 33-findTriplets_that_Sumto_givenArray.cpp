#include <bits/stdc++.h>
using namespace std;

// Finds triplets - O(n*logn) and O(1)
void findTriplets(int *A, int n, int sum){
    int i, l, r;
    i=0;
    r=n-1;

    sort(A, A+n); // Takes O(n*logn) T.C
    for(i=0; i<n-2; i++){
        l=i+1;
        
        while(l<r){
            if(A[i] + A[l] + A[r] == sum){
                cout<<"Triplets are : "<<A[i]<<" "<<A[l]<<" "<<A[r];
                break;
            }
            else if(A[i] + A[l] + A[r] < sum){
                l++;
            }
            else{
                r--;
            }
        }
    }
}


// Driver code
int main()
{
    // int A[] = {8, 7, 2, 5, 3, 1};
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int n = sizeof(A) / sizeof(A[0]);

    findTriplets(A, n, sum);
    return 0;
}