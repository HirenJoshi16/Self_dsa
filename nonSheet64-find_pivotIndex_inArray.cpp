// Program to find pivot index in an array ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print vector
void printVector(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

// #1 Method to find pivot index - O(N) & O(N)
int pivotIndex_1(vector<int>& nums){
    int n = nums.size();

    vector<int> leftSum(n), rightSum(n);
    leftSum[0] = nums[0];
    rightSum[n-1] = nums[n-1];

    // Build the left sum array 
    for(int i=1; i<n; i++)
        leftSum[i] = leftSum[i-1] + nums[i];

    // Build the right sum array 
    for(int i=n-2; i>=0; i--)
        rightSum[i] = rightSum[i+1] + nums[i];

    // Iterate and check for pivot index  
    for(int i=0; i<n; i++){   
        if(leftSum[i] == rightSum[i]) 
            return i;
    }
    
    return -1;
}

// #2 Method to find pivot index - O(N) & O(1)
int pivotIndex_2(vector<int>& nums){
    int totalSum = 0;
    
    for(auto val : nums)
        totalSum += val; // Find total sum

    int leftSum = 0;

    for(int i=0; i<nums.size(); i++){
        leftSum += nums[i];
        if(totalSum-leftSum == leftSum-nums[i])
            return i;
    }
    
    return -1;
}
// totalSum-leftSum --> Tracks right part sum for current index value
// leftSum-nums[i] --> Tracks left part sum for current index value

// Driver code
int main(){
    vector<int> arr{1, 2, 3, 4, 1, 3, 2}; 
    printVector(arr);

    // Method call
    int pIndex = pivotIndex_2(arr);
    cout<<"Pivot index is : "<<pIndex;

    return 0;
}
// Link : https://leetcode.com/problems/find-pivot-index/description/