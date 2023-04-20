// Program to find divisor with maximum divisibility score ~ coded by Hiren
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method to print vector 
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<' ';
        
    cout<<"    ";
}

// Method to find divisor with maximum divisibility score - O(N*M) & O(1)
int maxDivScore(vector<int>& nums, vector<int>& divisors){
    int maxDivisor = INT_MAX; // Stores result
    int maxScore = 0;
    
    for(int i=0; i<divisors.size(); i++){
        
        int score = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] % divisors[i] == 0) // When current element is divisible
                score++;
        }
        if(score > maxScore) // Check and store maximum score 
            maxScore = score,
            maxDivisor = divisors[i]; // Store the divisor
    
        else if(score == maxScore) // When there are multiple divisors with maximum score  
            maxDivisor = min(maxDivisor, divisors[i]); // Store the minimum divisor
        
    }
    return maxDivisor;
}

// Driver code
int main(){
    vector<int> nums{20, 14, 21, 10};
    vector<int> divisors{5, 7, 5};
    printVector(nums); printVector(divisors);

    // Method call
    int maxDivisor = maxDivScore(nums, divisors);
    cout<<"\nThe divisor with maximum divisibility score is : "<<maxDivisor;

    return 0;
}
// Link: https://leetcode.com/problems/find-the-maximum-divisibility-score/description/