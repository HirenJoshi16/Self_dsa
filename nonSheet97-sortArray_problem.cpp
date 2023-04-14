// Program to sort the given array ~ coded by Hiren
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Method to print array
void printArray(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";

    cout<<'\n';
}

// Method to sort the array using count sort - O(N+K) & O(N)
vector<int> sortArray(vector<int>& nums){
   unordered_map<int, int> hashMap;
   
   int maxVal = *max_element(nums.begin(), nums.end()); // Find the start point of range
   int minVal = *min_element(nums.begin(), nums.end()); // Find the end point of range

   for(auto val : nums)
        hashMap[val]++; // Store the value with its frequency

    int i = 0; // To iterate in array
    for(int currVal = minVal; currVal <= maxVal; currVal++){

        while(hashMap[currVal] > 0){ // Store the values in array 
            nums[i] = currVal;
            hashMap[currVal]--; 
            i++;
        }
        
    }
    return nums;
}

// Driver code
int main(){
    vector<int> nums{10, -2, 5, 3, 1, 0};
    printArray(nums);

    // Method call
    nums = sortArray(nums);
    printArray(nums);

    return 0;
}