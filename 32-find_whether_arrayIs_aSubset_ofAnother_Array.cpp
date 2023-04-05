#include <bits/stdc++.h>
using namespace std;

// Displays the elements
void printArray(int *P, int size){
    for(int i=0; i<size; i++){
        cout<<P[i]<<" ";
    }
}

// Checks is array2 is subset of array1
bool isSubset(int *A, int *B, int n, int m){
    unordered_set<int> uset;

    // Iterate array2 & put elements of it to uset
    for(int i=0; i<n; i++){
        uset.insert(A[i]);
    }

    // Iterate array1 & check is all element of uset is in array1 or not
    for(int i=0; i<m; i++){
        if(uset.find(B[i]) == uset.end()){
            return false;
        }
    }
    return true;
}

// Driver code
int main(){
    int A[] = {11, 1, 13, 21, 3, 7};
    int B[] = {11, 3, 7, 1};
    int n = 6;
    int m = 4;

    printArray(A, n);
    cout<<endl;
    printArray(B, m);

    cout<<endl;
    if(isSubset(A, B, n, m)){
        cout<<"Yes, its a subset";
    }
    else{
        cout<<"No, its not a subset";
    }
    return 0;
}