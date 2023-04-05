// Program to verify that can reach the last index or not ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays vector elements
void printVector(vector<int> nums, int i){
    if(i == nums.size()){
        cout<<endl; 
        return;
    }
    cout<<nums[i]<<" ";
    printVector(nums, ++i);
}

// Method to verify that can reach the last index or not - O(n) & O(1)
bool canJump(vector<int>& nums) {
    int n = nums.size();
    // Edge case
    if(nums.size()<=0) return false;
    int maxJump = 0; // Stores max number of jump

        for(int i=0; i<=maxJump; i++){
            // Store the max possibility to reach end
            maxJump = max(maxJump, nums[i]+i);
            // Return true if reached the last index
            if(maxJump >= n-1){
                return true;
            }
        }

    return false;
}
// Hint : max(maxJump, nums[i]+i); 
// maxJump indicates the maximum reach made from previous index
// nums[i]+i indicates the maximum index can reached from current index 

int main(){
    vector<int> nums{2, 1, 2, 3, 0, 0};
    printVector(nums, 0);

    // Method call
    if(canJump(nums))
        cout<<"Can jump to end";
    else    
        cout<<"Can not jump to end";

    return 0;
}
