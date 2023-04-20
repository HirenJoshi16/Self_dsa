// Program to find minimum difficulty of a job schedulling ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

// Method to print array
void printArray(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

int cache[301][11]; // For memoization, Sized according to constraints

// Method Helper: Finds minimum job schedulling from all the possibilities
int findMin(vector<int>& jobDiff, int n, int startIndex, int d){
    // When single day is left, We will do all the remaining difficulties and return the maximum of it
    if(d == 1)
        return *max_element(begin(jobDiff)+startIndex, end(jobDiff)); //

    // When result is already stored than no need to recompute, Simply return
    if(cache[startIndex][d] != -1)
        return cache[startIndex][d];

    int maxD = INT_MIN; // Tracks maximum difficulty from all for current day
    int finalAns = INT_MAX; // Stores final result


    // Take one job in single day, Than take two job in single day, And so on find the result from each possibility  
    for(int i = startIndex; i <= n-d; i++){ // i <= n-d -> Because we want to check possibilites correclty, For each day from given days

        maxD = max(maxD, jobDiff[i]); // Store the maximum difficulty for current day

        int ans = maxD + findMin(jobDiff, n, i+1, d-1); // Find and store the maximum difficulty of another day and so on for all the days 
        finalAns = min(finalAns, ans); // Store minimum difficulty of job schedulling 

    }

    return (cache[startIndex][d] = finalAns); // Store the result and return it
}

// Method to find minimum difficulty of a job schedulling - (N^2*D) & O(N*D) 
int minDifficulty(vector<int>& jobDiff, int d){
    memset(cache, -1, sizeof(cache)); // Create the cache array, For memoization
    int n = jobDiff.size();

    if(n < d) // When there is free remaining days than we cant schedule the job 
        return -1;

    return findMin(jobDiff, n, 0, d);
}

// Driver code
int main(){
    vector<int> jobDifficulty{6, 5, 4, 3, 2, 1}; int day = 2;
    printArray(jobDifficulty);

    // Method call
    int ans = minDifficulty(jobDifficulty, day);
    cout<<"The minimum difficulty of a job schedule is : "<<ans;

    return 0;
}
// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

/* 

Time complexity:
The time complexity of this code can be analyzed as follows:

The main function minDifficulty has a time complexity of O(n*d), where n is the size of the input jobDiff vector and d is the number of days.
The helper function findMin is called recursively in the minDifficulty function, and it has a time complexity of O(n^2d), as it has a nested loop that iterates through all the possible job schedules.
Therefore, the overall time complexity of the code is O(n^2d), which is polynomial in the input size.
Space complexity:
The space complexity of this code is O(nd), as the memoization table cache has a size of nd elements, and each element takes constant space. Additionally, the recursive calls to findMin may create a maximum of d nested function calls on the call stack, which also takes constant space. Therefore, the overall space complexity of the code is O(n*d).

*/