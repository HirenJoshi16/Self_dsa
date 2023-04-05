// Program to search aggregate index of given key in array ~ coded by vHiren 
// All the numbers in array are distinct and sorted
// Return the index if the target is found. If not, return the index where it would be if it were inserted in order
#include <iostream>
#include <vector>
using namespace std;

// Method to display vector elements
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
    cout<<endl;
}

// Method to search given key - O(logn) & O(1)
int searchInsert(vector<int>& nums, int key) {
    int low=0;
    int high=nums.size();
    // If given key has to be insert at last
    if(key>nums[high-1])
        return high;

        // Iterate logarithmically
        while(low<=high){
            int mid=(low+high)/2;

            // If given key is found
            if(nums[mid]==key)
                return mid;
                
            // When current value is lesser then result is on left side
            else if(nums[mid]<key)     
                low = mid+1;   
            
            // When current value is greater then result is on right side
            else
                high = mid-1;        
        }

    return low;
}

// Driver code
int main(){
    vector<int> nums{1, 2, 5, 7, 9};
    printVector(nums);
    int key = 4;

    // Method call
    int keyIndex = searchInsert(nums, key);
    cout<<"Aggregate index of "<<key<<" is "<<keyIndex;

    return 0;
}