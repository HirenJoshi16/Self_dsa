#include <bits/stdc++.h>
using namespace std;

// Prints array element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// Efficient method ~ O(n) & O(n)
void findElement(int *A, int k, int n){
    int x = n/k;
    unordered_map<int, int> freq;

    // Unordered map initialization by traversing the array
    for(int i=0; i<n; i++){
        freq[A[i]]++; // Store array elements to umap with its occurences, if occuring more than once thus increasing its frequency count
    }

    // Traversing the map
    for(auto i : freq){
        
        // If umap's any element occurence is greater than n/k which is x thus print that element
        if(i.second > x){
            cout<<i.first<<" ";
        }
    }
}

// Driver code
int main(){
    int A[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
	int n = sizeof(A) / sizeof(A[0]);
    int k = 4;

    printArray(A, n);
    cout<<endl;
    findElement(A, k, n);
    return 0;
}