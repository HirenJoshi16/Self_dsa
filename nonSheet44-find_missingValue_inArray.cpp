// Program to find missing number in array ~ coded by vHiren 
// All the numbers in array are distinct and unique just return the only number in the range[0, n], that is missing from the array
#include <iostream>
#include <vector>
using namespace std;

// Displays vector elements
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
    cout<<endl;
}

// Method to find missing number in vector - O(n) & O(1)
int missingNumber(vector<int>& nums){
    int n = nums.size();

        long rangeSum = 0;
        // Find cumulative sum of numbers in range 0-n
        for(int i=0; i<=n; i++)
            rangeSum += i;

        long pSum = 0;
        // Find cumulative sum of numbers of vector
        for(int i=0; i<n; i++)
            pSum += nums[i];

    return rangeSum - pSum;
}

// Driver code
int main(){
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    printVector(nums);

    // Method call
    int missingVal = missingNumber(nums);
    cout<<"Missing value is : "<<missingVal;

    return 0;
}