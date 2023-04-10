// Program to implement binary search recursively and iteratively ~ coded by Hiren
#include <iostream>
#include <vector>
using namespace std;

// #1 Method to find given target recursively - O(LogN) & O(LogN)
int searchRecursive(vector<int> nums, int l, int r, int target){
    if(l > r)
        return -1;

    int mid = l+(r-l)/2; // (r-l) To avoid integer overflow in case integer is very large

    if(nums[mid] == target)
        return mid;
    else if(nums[mid] < target)
        return searchRecursive(nums, mid+1, r, target);
    else
        return searchRecursive(nums, l, mid-1, target);
}

// #2 Method to find given target iteratively - O(LogN) & O(1)
int searchIterative(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    
        while(left <= right){
            int mid = left+(right-left)/2; // (right-left) To avoid integer overflow in case integer is very large

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;    
        }

    return -1;
}

// Driver code
int main(){
    vector<int> nums{-2, 0, 1, 2, 3, 4, 6, 7}; 
    int target = 7;
    // Method call
    int targetIndex = searchIterative(nums, target);
    cout<<target<<" found at index "<<targetIndex;

    return 0;
}