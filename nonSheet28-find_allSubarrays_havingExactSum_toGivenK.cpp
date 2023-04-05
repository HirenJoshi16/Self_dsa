// Program to find all subarray having exact sum to given k ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to display vector elements
void printVector(vector<int> nums){
    for(auto val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

// Method to find all subarray having exact sum to given k - O(n) & O(n)
int findAllSubarray_equalsK(vector<int>& nums, int k) {
    unordered_map<int, int> hashMap;
    int pSum = 0;
    int subArrayCount = 0;

        // Iterate till end
        for(int i=0; i<nums.size(); i++){
            pSum += nums[i];

            if(pSum == k) 
                subArrayCount++;
            // Check starting point is present for becoming subarray of sum k
            if(hashMap.count(pSum-k))
                subArrayCount += hashMap[pSum-k];

            hashMap[pSum]++; // Insert each time as current value's next value can be a starting point for any later subarray 
        }
    return subArrayCount;
}

// Driver code
int main(){
    vector<int> nums{1, 2, 3, 4, 5}; 
    int k = 9;
    printVector(nums);

    // Function call
    int subArrayCount = findAllSubarray_equalsK(nums, k);
    cout<<"Total subarrays having sum "<<k<<" is "<<subArrayCount;

    return 0;
}