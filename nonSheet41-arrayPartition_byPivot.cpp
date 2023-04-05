// Program to partition array according to given pivot ~ coded by vHiren 
// 1. Every element less than pivot appears before every element greater than pivot
// 2. Every element equal to pivot appears in between the elements less than and greater than pivot
// 3. The relative order of the elements less than pivot and the elements greater than pivot is maintained
#include <iostream>
#include <vector>
using namespace std;

// Displays vector elements
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
    cout<<endl;
}

// Method to partition array by given pivot - O(n) & O(n)
vector<int> pivotPartition(vector<int>& nums, int pivot) {
    int n = nums.size();
    // Edge case
    if(n<=0) 
        return nums;

    vector<int> ans;

    // Insert lesser elements
    for(auto i : nums){
        if(i < pivot) ans.push_back(i);
    } 
    // Insert equals
    for(auto i : nums){
        if(i == pivot) ans.push_back(i);
    } 
    // Insert greater elements
    for(auto i : nums){
        if(i > pivot) ans.push_back(i);
    } 
    
    return ans;
}

// Driver code
int main(){
    vector<int> nums{5, 1, 2, 6, 8, 7, 0, 3};
    printVector(nums);

    // Method call
    nums = pivotPartition(nums, 5);
    printVector(nums);

    return 0;
}