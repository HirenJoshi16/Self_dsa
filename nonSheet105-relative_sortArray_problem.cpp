// Program to sort given array1 such it maintains the relative order of array2 ~ coded by Hiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print array
void printArray(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

// Method to sort given array1 such it maintains the relative order of array2 - O(N+K) & O(N+K)
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2){
    const int k = 1001; // Make constant to prevent count array from resizing as we are using it statically 
    int count[k] = {0}; 
    vector<int> ans; // Stores result

    for(int i = 0; i < arr1.size(); i++) // Store frequency of each element 
        count[arr1[i]]++;

    // Store elements of arr2
    for(int i = 0; i < arr2.size(); i++){
        while(count[arr2[i]] > 0){ 
            ans.push_back(arr2[i]);
            count[arr2[i]]--; // Reduce the element frequency
        }
    }
    // Store the remaining elements of arr1
    for(int i = 0; i < k; i++){
        while(count[i] > 0){ 
            ans.push_back(i);
            count[i]--;
        }
    }

    return ans;
}

// Driver code
int main(){
    vector<int> arr1{28, 6, 22, 8, 44, 17};
    vector<int> arr2{22, 28, 8, 6};
    // Print given arrays
    printArray(arr1); printArray(arr2); cout<<'\n';

    // Method call
    vector<int> ans = relativeSortArray(arr1, arr2);
    printArray(ans);
    
    return 0;
}
// Link: https://leetcode.com/problems/relative-sort-array/description/