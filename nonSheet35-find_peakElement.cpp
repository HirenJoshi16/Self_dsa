// Program to find peak element ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays vector elements
void printVector(vector<int> vec){
    for(auto price : vec){
        cout<<price<<" ";
    }
    cout<<endl;
}

// Method to find peak element - O(logn) & O(1)
int findPeakElement(vector<int>& nums){
    // Edge case
    if(nums.size()<=0) return 0;

    int low = 0;
    int high = nums.size()-1;
    
    while(low < high){
        int mid = (low+high)/2;
        
        // If lesser then result is on right side
        if(nums[mid] <= nums[mid+1])
            low = mid+1;
        // Else result is on left side
        else    
            high = mid;
    }

    return low;
}   

// Driver code
int main(){
    vector<int> nums{1, 2, 0, 7, 8 ,5};
    printVector(nums);

    // Method call
    int peakIndex = findPeakElement(nums);
    cout<<"Element found at index : "<<peakIndex; 

    return 0;
}