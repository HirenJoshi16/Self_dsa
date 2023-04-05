// Program to rotate array to right by k steps ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print vector
void printVector(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

// #1 Method to rotate array by k - O(n) & O(n)
void rotateByK(vector<int> &arr, int n, int k){
    vector<int> temp(n);
    
    for(int i=0; i<n; i++)
        temp[((i+k) % n)] = arr[i]; // Place element at its rotation index

    arr = temp; // Replace the original array elements
}

// #2 Helper Method to reverse array elements
void reverse(vector<int> &arr, int low, int high){
    while(low < high){
        // Swap the elements
        int tmp = arr[low];
        arr[low] = arr[high];
        arr[high] = tmp;
        
        low++; 
        high--;
    }
}

// #2 Method to rotate array by k - O(n) & O(1)
void rotateByK_2(vector<int> &arr, int n, int k){
    // Edge case
    if(k > n)
        k = k%n;

    int low = 0; int high = n-1;

    // Reverse original array
    reverse(arr, low, high);

    // Reverse k part
    reverse(arr, low, k-1);

    // Reverse remaining array
    reverse(arr, k, high);
}

// Driver code
int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7}; 
    int n = arr.size(); int k = 4; 
    printVector(arr);

    // Method call
    rotateByK_2(arr, n, k); printVector(arr);

    return 0;
}