// Program to find the largest perimeter of a triangle with a non-zero area ~ coded by Hiren
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Method to print vector
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
        
    cout<<"\n";
}

// Method to find largest perimeter of a triangle with a non-zero area - O(NLogN) & O(1)
int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Requires to ease the process by avoid checking all the 3 properties of a triangle with a non-zero area

    for(int i=n-3; i>=0; i--){
        if(nums[i] + nums[i+1] > nums[i+2]) // Sorting helps us to make it using a single property -> a + b > c 
            return nums[i] + nums[i+1] + nums[i+2];
    }
    return 0;
}

// Driver code
int main(){
    vector<int> nums{3, 1, 2, 4};
    printVector(nums);

    // Method call
    int perimeter = largestPerimeter(nums);
    cout<<"Largest perimeter is : "<<perimeter;

    return 0;
}
// Link: https://leetcode.com/problems/largest-perimeter-triangle/description/

// Note: The 3 properties of a triangle with a non-zero area :-
// Let say we have three sides in it - a, b, c
// 1. a + b > c
// 2. b + c > a
// 3. c + a > b