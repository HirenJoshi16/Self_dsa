// Program to find majority element ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays array elements
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// #1 Method to find majority element - O(n) & O(1)
int majorityElement(int* A, int n){
    // Edge case
    if(n<=0) return 0;
    
    int currMajorityVal = A[0];
    int count = 0;
        // Iterate till end
        for(int i=0; i<n; i++){
            // If the count is 0, it means we have not found majority element candidate yet, hence we set currMajorityVal to current element
            if(count == 0) currMajorityVal = A[i];
            
            // If the count is not 0, it means we already have a majority element candidate, hence we check if the current element is the same as currMajorityVal
            count += (currMajorityVal == A[i]) ? 1 : -1;
        }
    return currMajorityVal;
}
// For each element in the array:
// If the count is 0, it means we have not found majority element candidate yet, hence we set currMajorityVal to current element
// If the count is not 0, it means we already have a majority element candidate, hence we check if the current element is the same as currMajorityVal
// If it is, we increment the count, because the current element contributes to the majority count of currMajorityVal
// If it is not, we decrement the count, because the current element reduces the majority count of currMajorityVal


// #2 Method to find majority element - O(n*logn) & O(1)
int findMajority(int *A, int n){
    // Edge case
    if(n<=0) return 0;

    int i=0; 
    int j=i+1; 
    int count=1;
    sort(A, A+n); // Sort the array
        
        while(j<n+1){
            // If value counts turn out to be upper bound of condition
            if(count > n/2){
                return A[i];
            }
            else if(A[i] == A[j]){
                count++;
                i++; j++;
            }
            else if(A[i] != A[j]){
                count = 1;
                i++; j++;
            }
            else{
                return -1;
        }
    }
    return 0;
}

// Driver code
int main(){
    int A[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    cout<<endl;

    // Method call
    if(int val = majorityElement(A, n)){
        cout<<"Element is : "<<val;
    }
    else{
        cout<<"No majority element!";
    }
    
    return 0;
} 