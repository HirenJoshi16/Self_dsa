// Program to verify there contains duplicate in given array ~ coded by Hiren
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

// Method to print given array
void printArray(vector<int> nums){
    for(auto val : nums)    
        cout<<val<<" ";
        
    cout<<'\n';
}

// Method to verify there contains duplicate in given array - O(N) & O(N)
bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int> hashMap;

    for(int i=0; i<nums.size(); i++){
        if(hashMap.count(nums[i]) && abs(hashMap[nums[i]] - i) <= k)
            return true;
        else
            hashMap[nums[i]] = i;
    }
    return false;
}

// Same method with better readability but increases runtime and memory usage - O(N) & O(N)
bool containsNearbyDuplicate_Readable(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> hashMap;
    bool containDuplicate = false;

    for(int i=0; i<n; i++){
        int currVal = nums[i]; // Store current value
        if(hashMap.count(currVal)){ // If current value presents in map
            int absDifference = abs(hashMap[currVal] - i); // Take the absolute difference

            if(absDifference <= k){
                containDuplicate = true;
                break;
            }
        }
        hashMap[currVal] = i; // Store currVal as key and its index as value
    }

    return (containDuplicate ? true : false);
}

// Driver code
int main(){
    vector<int> nums{1, 0, 2, 4, 1};
    printArray(nums);

    // Method call
    if(containsNearbyDuplicate(nums, 5))
        cout<<"Such duplicate exist!";
    else
        cout<<"Such duplicate does not exist!";

    return 0;
}
// Link: https://leetcode.com/problems/contains-duplicate-ii/