// Program to find minimal length of subarray of given k ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to display vector elements
void printVector(vector<int> nums){
    for(auto val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

// Method to find minimal length of subarray of given k - O(n) & O(1) | Sliding Window Technique
int findMinSubArrayLen(vector<int>& nums, int k){
    int sum = 0;
    int windowStart = 0; // Indicates start index 
    int minLength = INT_MAX;
    
    // Iterate till end
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        
        // Greater then pick next window 
        while(sum >= k){
            minLength = min(minLength, i+1-windowStart);
            sum -= nums[windowStart++]; // Update sum and then increment windowStart
        }

    }
    return (minLength == INT_MAX ? 0 : minLength);
}

// Driver code
int main(){
    vector<int> nums{1, 2, 3, 4, 5}; 
    int k = 5;
    printVector(nums);

    // Function call
    int minLength = findMinSubArrayLen(nums, k);
    cout<<"Minimum subarray length : "<<minLength;

    return 0;
}