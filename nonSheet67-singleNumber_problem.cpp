// Program to find single non-repeating value in array ~ coded by vHiren
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Method to print vector
void printVector(vector<int> vec){
    for(auto val : vec)
        cout<<val<<" ";

    cout<<'\n';
}

// #1 Method to find single number in array - O(N) & O(N)
int singleNumber_1(vector<int>& nums){
    set<int> hashSet;
    // Insert unique elements 
    for(auto val : nums)
        hashSet.insert(val);

    int idealSum = 0;
    // Ideally, We know each element can only repeats twice
    for(auto val : hashSet)
        idealSum += val;
    idealSum *= 2; // Hence multiply 2

    int actualSum = 0;
    // Take the actual sum
    for(auto val : nums)
        actualSum += val;

    return (idealSum-actualSum);
}

// #2 Method to find single number in array - O(N) & O(1)
int singleNumber_2(vector<int>& nums){
    int ans = 0;
    for(auto val : nums)
        ans ^= val;

    return ans;
}

// Driver code
int main(){
    vector<int> vec{4, 2, 1, 2, 1};
    printVector(vec);

    // Method call
    int singleVal = singleNumber_1(vec);
    cout<<"The single value is : "<<singleVal;

    return 0;
}