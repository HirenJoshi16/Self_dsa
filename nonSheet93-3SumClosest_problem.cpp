// Program to find sum of three integers such sum is closest to given target ~ coded by Hiren
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// Method to print vector
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
        
    cout<<"\n";
}

// #1 Method to find sum of three integers such sum is closest to given target - O(N*N*N) & O(1)
int threeSumClosest_1(vector<int>& nums, int target){
    int n = nums.size();
    int closestSum = INT_MAX; // Stores the result

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(abs(target - closestSum) > abs(target - (nums[i] + nums[j] + nums[k]))) // Check the closest distance than take the closest sum accordingly
                    closestSum = (nums[i] + nums[j] + nums[k]);
            }
        }
    }
    return closestSum;
}

// #2 Method to find sum of three integers such sum is closest to given target - O(N*N) & O(1)
int threeSumClosest_2(vector<int>& nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Requires to apply Two-Pointer Technique correctly
    int closestSum = 100001; // Stores the result

    for(int k = 0; k < n-2; k++){
        int l = k+1;
        int r = n-1;

        while(l < r){
            int sum = nums[k] + nums[l] + nums[r]; // Take the sum

            if(abs(target - sum) < abs(target - closestSum)) // Check the closest distance than take the closest sum accordingly
                closestSum = sum;

            if(sum < target)
                l++; 
            else
                r--;
        }
    }
    return closestSum;
}

// Driver code
int main(){
    vector<int> nums{1, 2, 3, 4, -5}; int target = 10;
    printVector(nums);

    // Method call
    int closestSum = threeSumClosest_2(nums, target);
    cout<<"The closest sum to "<<10<<" is : "<<closestSum;

    return 0;
}