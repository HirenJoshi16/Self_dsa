// Program to sort given array of zeros, ones and twos ~ coded by Hiren
// Note: Problem known as Dutch National Flag Problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// Method to print given array
void printArray(vector<int> nums){
    for(auto val : nums)    
        cout<<val<<" ";
        
    cout<<'\n';
}

// #1 Method to sort given array of zeros, ones and twos - O(NLogN) & O(1)
void sortColors_1(vector<int>& nums){
    sort(begin(nums), end(nums));
}

// #2 Method to sort given array of zeros, ones and twos - O(N) & O(1)
void sortColors_2(vector<int>& nums){
    int zeros = 0; // Tracks zeros count
    int ones = 0; // Tracks ones count
    int twos = 0; // Tracks twos count

    for(auto val : nums){
        if(val == 0) 
            zeros++; // When current value is 0
        else if(val == 1) 
            ones++; // When current value is 1
        else 
            twos++; // When current value is 2
    }

    for(int i=0; i<nums.size(); i++){
        if(zeros > 0)
            nums[i] = 0, // Replace current index value to 0 
            --zeros;

        else if(ones > 0)
            nums[i] = 1, // Replace current index value to 1
            --ones;

        else 
            nums[i] = 2, // Replace current index value to 2 
            --twos;
    }
}

// #3 Method to sort given array of zeros, ones and twos - O(N) & O(1)
void sortColors_3(vector<int>& nums){
   int i = 0; // Tracks zero
   int j = 0; // Tracks one
   int k = nums.size()-1; // Tracks two

    while(j <= k){
        if(nums[j] == 1) // When current element is 1
            j++;
        else if(nums[j] == 2) // When current element is 2
            swap(nums[j], nums[k]), 
            k--;
        else
            swap(nums[j], nums[i]), // When current element is 0
            i++, 
            j++;
    }
}

// Driver code
int main(){
    vector<int> nums{2, 0, 2, 1, 1, 0};
    printArray(nums);

    // Method call
    sortColors_3(nums);
    printArray(nums);

    return 0;
}
// Link: https://leetcode.com/problems/sort-colors/