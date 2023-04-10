// Program to find total number of subarrays whose sum is divisible by K ~ coded by vHiren
#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>

// Method to print vector
void printVector(std::vector<int> nums){
    for(auto val : nums)
        std::cout<<val<<" ";

    std::cout<<'\n';    
}

// #1 Method to find total number of subarrays whose sum is divisible by K - O(N*N*N) & O(1)
int subarraysDivByK_1(std::vector<int>& nums, int k){
    int n = nums.size();
    int subArrayCount = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = accumulate(begin(nums)+i, begin(nums)+j+1, 0);
            // The accumulate() method takes O(given_rangeToSum) time hence it takes O(N) in the worst case 
            if(sum%k == 0)
                subArrayCount++;
        }
    }
    
    return subArrayCount;
}

// #2 Method to find total number of subarrays whose sum is divisible by K - O(N*N) & O(1)
int subarraysDivByK_2(std::vector<int>& nums, int k){
    int n = nums.size();
    int subArrayCount = 0;

    // Update to prefix sum to take sum in O(1)
    for(int i = 1; i < n; i++)
        nums[i] += nums[i-1];

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1]; // Constant time idea to take sum

            if(sum%k == 0)
                subArrayCount++;
        }
    }
    
    return subArrayCount;
}
// Note : Can take sum for subarrays in O(1) time using prefix sum idea

// #3 Method to find total number of subarrays whose sum is divisible by K - O(N) & O(N)
int subarraysDivByK_3(std::vector<int>& nums, int k){
    std::unordered_map<int, int> hashMap;

    hashMap[0] = 1; // Requires for special cases
    int pSum = 0;
    int subArrayCount = 0;

        for(int i = 0; i < nums.size(); i++){
            pSum += nums[i];
            int rem = pSum%k; // Take remainder

            // If negative, sum K to it because we want the track of each subarray
            if(rem < 0)
                rem += k;

            // If presents hence found an subarray from the next element of the remainder element to the current element
            if(hashMap.count(rem))
                subArrayCount += hashMap[rem];

            hashMap[rem]++; // Increse frequency each time as its possible their can be alot subarrays with same remainder
        }

    return subArrayCount;
}

// Driver code
int main(){
    std::vector<int> nums{2, -6, 3, 1, 2, 8, 2, 1};
    printVector(nums); int k = 7;
    
    // Method call
    int subArrayStreak = subarraysDivByK_3(nums, k);
    std::cout<<"Total subarrays whose sum is divisible by "<<k<<" is : "<<subArrayStreak;

    return 0;
}