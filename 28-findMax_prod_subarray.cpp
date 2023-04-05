// Program to find maximum product of subarray ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Prints array element
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

// #1 Method to find maximum product - O(n) & O(1) 
int maxProduct1(int* nums, int n){
    int maxProduct = 1; // To calculate and store max product at each subarray
    int minProduct = 1; // Needed when nums[i] is negative
    int ans = INT_MIN; // Stores final result

        for(int i=0; i<n; i++){
            // Swap because we want maximum product and for that we have to store maximum in maxProduct or if we don't swap minProduct will store maximum and maximum will store minimum which is wrong because we want maxProduct to store maximum
            if(nums[i] < 0) 
                swap(maxProduct, minProduct);

            maxProduct = max(nums[i], maxProduct*nums[i]);
            minProduct = min(nums[i], minProduct*nums[i]);
            ans = max(ans, maxProduct);
        }

    return ans;
}
// max(nums[i], maxProduct*nums[i]) :-
// nums[i] - Possibility of start of a new subarray
// maxProduct*nums[i] - Possibility of subarray is already started thus calculate current element with previous product 


// #2 Method to find maximum product - O(n) & O(1) 
int maxProduct2(int *A, int n){
    int currProd = 1;
    int maxProd = 1;

    // Iterate from left to right & find maximum product
    for(int i=0; i<n; i++){
        currProd *= A[i];
        maxProd = max(maxProd, currProd);
        
        if(currProd==0){
            currProd = 1;
        }
    }
    // Set currnt product again to 1 as it contains the first loops product
    currProd=1;
    // Iterate from right to left & find maximum product
    for(int i=n-1; i>=0; i--){
        currProd *= A[i];
        maxProd = max(maxProd, currProd);
        
        if(currProd==0){
            currProd = 1;
        }
    }

    return maxProd;
}

// Driver code
int main(){
    int A[] = {5, -1, 2, -3, 4};
	int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    cout<<endl;

    // Method call
    cout<<"Max Product is : "<<maxProduct1(A, n);

    return 0;
}