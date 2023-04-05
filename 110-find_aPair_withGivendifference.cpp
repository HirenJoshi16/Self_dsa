// Program to find pair with given difference k, can also be done by hashing
#include <bits/stdc++.h>
using namespace std;

// Displays each element to array
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// Find pairs with given difference k ~ O(nlogn) & O(1)
bool findPair(int *A, int k, int n){
    sort(A, A+n);

    int l, r;
    l=0;
    r=1;
    // Itrate the array
    while(l<n && r<n){
        int diff = A[r] - A[l];

        // We need distinct elements thus l!=r
            if(diff == k && l!=r){
                cout<<"Pair found : "<<"("<<A[l]<<", "<<A[r]<<")";
                return true;
            }
            if(diff>k){
                l++;
            }
            else{
                r++;
            }
        }
    cout<<"No such pair";
    return false;
}

// Driver code
int main(){
    int A[] = {200, 3, 40, 100, 10, 50};
    // int A[] = {1, 3, -10, 5, 40, 36};
    int n = 6;
    int k = 100;
    printArray(A, n);
    findPair(A, k, n);
    return 0;
}