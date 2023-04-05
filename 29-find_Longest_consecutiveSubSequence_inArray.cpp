// Program to find longest consecutive Subsequence in array ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays vector elements
void printVector(vector<int> vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

// #1 - Function to find longest consecutive Subsequence ~ O(n*logn) & O(1)
int findLongestConseqSubseq(vector<int>& vec){
    // Edge case
    if(vec.size() <= 0) return 0;

    // Sort the vector
    sort(vec.begin(), vec.end());
    int subSeqCount = 0;
    int currCount = 0;

        // Iterate vector till end
        for(int i=0; i<vec.size(); i++){
            // Check current element is equal to prev element + 1
            if(i > 0 && vec[i] == vec[i-1]+1)
                currCount++;
            // Reset current count to 1
            else
                currCount = 1;
            subSeqCount = max(currCount, subSeqCount); // Update longest subSeq count each time
        }
    return subSeqCount;
}  

// #2 - Function to find longest consecutive Subsequence ~ O(3n) & O(n)
int longestConsecutive(vector<int>& vec){
    // Edge case
    if(vec.size() <= 0) return 0;

    unordered_set<int> hashSet; // Create a set
    // Insert all vector elements once to set ~ Set does not contain duplicates 
    for(auto val : vec) hashSet.insert(val);

    int longestStreak = 0; int currStreak = 0; int currNumber = 0;

    // Iterate vector till end
    for(int num : vec){
        // Check if previous value of current value is not present in hashSet 
        if(!hashSet.count(num-1)){
            currNumber = num;
            currStreak = 1; // Assuming starting Subsequence is from current value
            
            // Increment current streak if current + 1 value is present in set
            while(hashSet.count(currNumber+1)){
                currNumber += 1;
                currStreak += 1;
            }
            
            // Update maximum subsequence if previous value of current value is not present in hashSet 
            longestStreak = max(currStreak, longestStreak); 
        }
    }
    return longestStreak;
}      

// Driver code
int main(){
    vector<int> vec{2, 6, 1, 9, 4, 5, 3};
    printVector(vec);

    // Function call
    int longestSubSeq = longestConsecutive(vec);
    if(longestSubSeq)
        cout<<"Longest ConseqSubSeq : "<<longestSubSeq;
    else
        cout<<"Human Error!";

    return 0;
}