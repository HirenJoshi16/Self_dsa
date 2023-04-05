// Program to find maximum subarray with equal number of ones and zeros in a binary array ~ coded by vHiren
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Displays vector elements
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
    cout<<endl;
}

// Method to find maximum length of subarray with equal number of ones and zeros - O(n) & O(n)
int findMaxLength(vector<int>& nums){
    int n = nums.size();
    // Replace zeros by -1 because we know whenever the sum gets 0 we absolutely have a valid subarray with equal number of ones and zeros 
    for(int i=0; i<n; i++){
        if(nums[i] == 0) 
            nums[i] = -1;
    }
    
    unordered_map<int, int> hashMap;
    int sum = 0;
    int maxStreak = 0;       

        // Iterate till end
        for(int i=0; i<n; i++){
            sum += nums[i];
            // If its zero thus we have found a valid subarray from starting index 0 to current index i
            if(sum == 0)
                maxStreak = max(maxStreak, i+1);

            // If current sum is present in map that means we have found a valid subarray from this hashmap's sum index+1 to current index
            if(hashMap.count(sum))
                maxStreak = max(maxStreak, i-hashMap[sum]);
            // Else store because current sum index+1 to upcoming index of later can be a valid subarray
            else
                hashMap[sum] = i;
        }
                     
    return maxStreak;
}

// Driver code
int main(){
    vector<int> nums{1, 0, 1, 1, 0, 1, 0};
    printVector(nums);

    // Method call
    int maxStreak = findMaxLength(nums);
    cout<<"Maximum subarray length is "<<maxStreak;

    return 0;
}