// Program to find two numbers sums to given target ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print vector
void printVector(vector<int> vec) {
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

// Method to find two numbers sums to given target - O(N) & O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int i = 0, j = n-1;

        while(i < j){
            int sum = numbers[i] + numbers[j];

            if(sum < target)
                i++;
            else if(sum > target)
                j--;
            else
                return {i+1, j+1};
        }

    return {}; // Return empty vector in case not found
}

// Driver code
int main() {
    vector<int> vec{1, 2, 3, 4}; printVector(vec);
    int target = 7;

    // Function call
    vec = twoSum(vec, target);
    printVector(vec);

    return 0;
}
// Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/