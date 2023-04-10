// Program to find all the triplets sums to zero ~ coded by vHiren
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Method to print vector
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
        
    cout<<"\n";
}

// Helper Method: finds remaining two numbers using twoSum problem technique for each element
void twoSum(vector<int>& nums, int target, vector<vector<int>>& ans, int i, int j){
    while(i < j){
        // Check for n3 when sum is greater
        if(nums[i] + nums[j] > target){
            j--;
        }
        // Check for n2 when sum is lesser
        else if(nums[i] + nums[j] < target){
            i++;
        }
        // In case n2 and n3 found
        else{
            // Store the triplets, Remember - Store the target value in its actual form
            ans.push_back({-target, nums[i], nums[j]});

            // If duplicate presents, skip elements to avoid storing duplicates
            while(i < j && nums[i] == nums[i+1])
                i++;
            // If duplicate presents, skip elements to avoid storing duplicates
            while(i < j && nums[j] == nums[j-1])
                j--;

            i++; j--;
        }
    }
}

// Method to find all the triplets that sums to zero - O(N*N) & O(N)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(begin(nums), end(nums)); // Requires to avoid issue of triplets being on the left side for any element as we are using twoSum technique

    // Iterate till n-2 times as its not possible to find triplets for last two elements
    for(int i = 0; i < n-2; i++){
        // Requires to avoid duplicating because duplicate element gives the same triplets
        // Initially no duplicate we see for i = 0
        if(i != 0 && nums[i] == nums[i-1])
            continue;

        // Find remaining two numbers using twoSum technique -> Take nums[i] as -n1
        twoSum(nums, -nums[i], ans, i+1, n-1);
    } 
    
    return ans;
}
// We have to find the three numbers which sums zero thus we can write -> n1 + n2 + n3 = 0
// It can be written as: n2 + n3 = -n1 --> This one also brings the same result hence this idea is taken for each nums[i] to find triplet thus its necessary to take -nums[i] instead of nums[i]

// Method to print 2D vector
void printVector2D(vector<vector<int>> ans){
    for(int i = 0; i < ans.size(); i++)
            cout<<ans[i][0]<<", "<<ans[i][1]<<", "<<ans[i][2]<<endl;
}

// Driver code
int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    printVector(nums);

    // Method call
    vector<vector<int>> ans = threeSum(nums); 
    printVector2D(ans);

    return 0;
}