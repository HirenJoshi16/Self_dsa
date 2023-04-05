// Program to find element that appears exactly once in sorted array ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to display vector elements
void printVector(vector<int> nums){
    for(auto val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

// #1 Method to find element which appears exactly once - O(logn) & O(1)
int singleNonDuplicate1(vector<int>& nums) {
    // Edge case
    if(nums.size() == 1) return nums[0];

    int low = 0;
    int high = nums.size()-1;

        while(low < high){
            int mid = (low + high)/2;
            
            // If current index is odd then result is on left side
            if(mid%2 == 1)
                mid--;

            // If both values are not same then result is on left side  
            if(nums[mid] != nums[mid+1])
                high = mid;
            // If both values are same then result is on right side
            else
                low = mid+2;
        }

    return nums[low];
}

// #2 Method to find element which appears exactly once - O(n) & O(1)
int singleNonDuplicate2(vector<int>& nums) {
    // Edge case
    if(nums.size() == 1) return nums[0];
    
    int i=1;
    // If its the first element
    if(nums[0] != nums[i]) return nums[0];

        // Iterate till end
        while(i < nums.size()){
            // When duplicate of current value is not present
            if(nums[i] != nums[i+1] && nums[i] != nums[i-1])
                return nums[i];
            i++;
        }
        
    return -1;
}

// Driver code
int main(){
    vector<int> nums{1, 1, 2, 4, 4}; 
    printVector(nums);

    // Method call
    int nonDuplicate = singleNonDuplicate1(nums);
    cout<<"The value that appears only once is : "<<nonDuplicate;

    return 0;
}