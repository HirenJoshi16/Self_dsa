// Program to find kids with greatest number of candies ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to print array
void printArray(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

// Method to find kids with greatest number of candies - O(N) & O(N)
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans(candies.size(), false);
    int maxCandy = *max_element(candies.begin(), candies.end());

    for(int i=0; i<candies.size(); i++){
        if((candies[i] + extraCandies) >= maxCandy)
            ans[i] = true;
    }
    return ans;
}

// Driver code
int main(){
    vector<int> candies{2, 3, 5, 1, 3}; 
    int extraCandies = 3;
    printArray(candies);

    // Method call
    vector<bool> ans = kidsWithCandies(candies, extraCandies);
    // Print result
    for(auto val : ans)
        cout<<(val ? "true" : "false")<<" ";
    
    return 0;
}
// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/