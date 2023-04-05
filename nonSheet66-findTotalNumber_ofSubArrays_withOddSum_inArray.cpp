// Program to find total number of sub-arrays with odd sum in array ~ coded by vHiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to find number of total sub-arrays with odd sum - O(N) & O(1)
int numOfSubArrays(vector<int> arr){
    int mod = 1e9+7; // Essential to avoid integer overflow when this sum -> (subArraysTillNow + odd) is very large

    int even, odd;
    even = odd = 0;
    int subArraysTillNow = 0;

        for(auto i : arr){
            // If current value is even
            if(i%2 == 0)
                even++;
            // If current value is odd
            else
                swap(even, odd),
                odd++;

            subArraysTillNow = (subArraysTillNow + odd) % mod; // Tracks total odd sum subarrays can made till now
        }

    return subArraysTillNow; 
}
// Swapping of even and odd is essential to track correct numbers of subarrays with odd sum seen so far!
// odd : Keeps track of all odd sum subarrays, can be made from current value to previously ending odd number in it

// Driver code
int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};

    // Method call
    int subArrays = numOfSubArrays(arr);
    cout<<"Total subarrays with odd sum is "<<subArrays;

    return 0;
}