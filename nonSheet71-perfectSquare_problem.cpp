// Program to find the least number of perfect square numbers that sum to N ~ coded by vHiren
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int dp[10001]; // N+1 sized for memoization, According to given constraint (1 <= n <= 10^4)

// Helper Method : finds least number of perfect squares sums N - O(N*sqrt(N)) & O(N)
int minSquares(int n) {
    if(n == 0)
        return 0;

    // Memoization -> If N is present than no recomputation needed just return its computed value 
    if(dp[n] != -1) 
        return dp[n];

    int minCount = INT_MAX;

    for(int i = 1; i*i <= n; i++) {
        // At first we are taking single perfect square to begin, which is (i*i) hence -> 1 + minSquares(n - i*i) 
        int ans = 1 + minSquares(n - i*i);
        minCount = min(minCount, ans); 
    }

    return (dp[n] = minCount); // Store the count of current N and return the count
}

// Method to find least number of perfect squares sums N
int numSquares(int n) {
   memset(dp, -1, sizeof(dp)); // Initializing all the blocks of dp[10001] to -1

   return minSquares(n); 
}

// Driver code
int main() {
    int n = 12;
    // Method call
    int leastSquaresCount = numSquares(n);
    cout<<"The least number of perfect squares that sum upto "<<n<<" is "<<leastSquaresCount;

    return 0;
}
// Link : https://leetcode.com/problems/perfect-squares/description/

// The time complexity of the given code is O(nsqrt(n)), as there is a for loop that iterates up to sqrt(n) times, and for each iteration, the recursive function minSquares is called. In the worst case, the function minSquares can also iterate up to sqrt(n) times for each recursive call, resulting in a total of n iterations. Therefore, the time complexity is O(nsqrt(n)).

// Regarding the space complexity, it is O(n) due to the size of the dp array, which has n+1 elements, and the maximum call stack depth of the recursive function minSquares is O(sqrt(n)).