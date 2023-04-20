// Program to find maximum profit in a job schedulling ~ coded by Hiren
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

// Method to print array
void printArray(vector<int> arr){
    for(auto val : arr)
        cout<<val<<" ";

    cout<<'\n';
}

int n; // sizeof(startTime)
int memz[50001]; // For memoization, Sized according to constraints

// Method Helper: Finds nextJobIndex such that the nextJob Starting time should be greater than Or equal to currJobEndTime
int findNextJob(vector<vector<int>>& array, int low ,int currJobEndTime){
    int high = n-1;
    int ans = INT_MAX; // Initialize ans to a large value to find the leftmost index of the next job that starts after the current job ends. If no such index exists, the function returns INT_MAX

    while(low <= high){
        int mid = low + (high-low) / 2; // (high-low) : To avoid integer overflow when number goes larger

        if(array[mid][0] >= currJobEndTime)
            ans = mid,
            high = mid-1; // Requires when there are jobs with duplicate start times and in this cases we want the leftmost job index
        else 
            low = mid+1;
    }
    return ans;
}

// Method Helper: Finds the maximum profit
int maxProfit(vector<vector<int>>& array, int index){
    // Edge case
    if(index >= n)
        return 0;

    if(memz[index] != -1)
        return memz[index]; // If maximum profit is already computed for current index than return it without computing again

    int nextJobIndex = findNextJob(array, index+1, array[index][1]); // Find the nextJob to take

    // There are always two possibility of taking any job:-
    // 1. Is the possibility of taking the current one
    int currTaken = array[index][2] + maxProfit(array, nextJobIndex); 
    // 1. Or the possibility of not taking the current one, Means skip the current one
    int currNotTaken = maxProfit(array, index+1);

    return memz[index] = max(currTaken, currNotTaken); // Store the current index profit and return it
}

// Method to find maximum profit in a job schedulling - O(NLogN) & O(N)
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
    n = startTime.size();
    memset(memz, -1, sizeof(memz));

    vector<vector<int>> array(n, vector<int>(3, 0)); // Used to store -> {startTime, endTime, profit}
    
    // Store the values to array
    for(int i=0; i<n; i++){
        array[i][0] = startTime[i];
        array[i][1] = endTime[i];
        array[i][2] = profit[i];
    }

    // Lambda Method / Comparator : Used while sort by comparing startTime of jobs 
    auto comp = [](auto& vec1, auto& vec2){
        return vec1[0] <= vec2[0];
    };
    sort(begin(array), end(array), comp); // Sort according to startTime of the jobs
    // Note: By Default the sort method sorts according to the startTime but still its better to know

    int startIndex = 0;
    return maxProfit(array, startIndex);
}

// Driver code
int main(){
    vector<int> startTime{1,2,3,3}, endTime{3,4,5,6}, profit{50,10,40,70};
    // Print arrays
    cout<<"StartTime : "; printArray(startTime); 
    cout<<"EndTime : "; printArray(endTime); 
    cout<<"Profit : "; printArray(profit);
    cout<<'\n';

    // Method call
    int ans = jobScheduling(startTime, endTime, profit);
    cout<<"The maximum profit is : "<<ans;

    return 0;
}
// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
