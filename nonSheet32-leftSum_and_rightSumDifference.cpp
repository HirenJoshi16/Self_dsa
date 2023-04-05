// Program to find absolute difference of each value by leftsum and rightsum ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to display vector elements
void printVector(vector<int> nums){
    for(auto val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

// Method to find absolute difference of each value by leftsum and rightsum - O(n) & O(n)
vector<int> leftRightDifference(vector<int> &nums){
    int n = nums.size();

    // Edge case
    if(n <= 0) return nums;

    // To store prefix sum
    long long pSumLeft = 0, pSumRight = 0;
    // To store result for later calucaltion
    long long leftSumArray[n], rightSumArray[n];

    // Iterate and store leftsum of each value
    for(int i=0; i<n; i++){
        pSumLeft += nums[i];
        leftSumArray[i] = pSumLeft;
    }
    // Iterate and store rightsum of each value
    for(int i=n-1; i>=0; i--){
        pSumRight += nums[i];
        rightSumArray[i] = pSumRight;
    }
    // Store absolute difference
    for(int i=0; i<n; i++)
        nums[i] = abs(leftSumArray[i] - rightSumArray[i]);

    return nums;
}

// Driver code
int main(){
    vector<int> nums{1, 2, 3, 4}; 
    printVector(nums);

    // Method call
    nums = leftRightDifference(nums);
    printVector(nums);

    return 0;
}