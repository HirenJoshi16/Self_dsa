// Program to verify there exist a good subarray or not in an array ~ coded by vHiren
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method to print vector
void printVector(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

// Method to verify good subarray exist or not - O(N) & O(N)
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hashMap;
    hashMap[0] = 0; // Handle special cases

    int pSum = 0;

        for(int i=0; i<nums.size(); i++){
            pSum += nums[i];

            // If remainder is not present, insert current sum remainder as it could be a starting point for being a good subarray later
            if(!hashMap.count(pSum%k)){
                hashMap[pSum%k] = i+1; // i+1 needed to verify whenever a good subarray exist it has size greater or equal to 2 or not
            }
            // If remainder is present, it means previously there found a good subarray from its index value to current index
            // Or the sum of elements from that index value to current index is an multiple of k 
            // Return true if existing good subarray has least size 2
            else if(hashMap[pSum%k] < i){
                return true;
            }
        }

    return false;
}

// Driver code
int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7}; 
    int k = 10; printVector(arr);

    // Method call
    if(checkSubarraySum(arr, k))
        cout<<"Good subarray exist!";
    else
        cout<<"Good subarray does not exist!";

    return 0;
}
// Link : https://leetcode.com/problems/continuous-subarray-sum/description/