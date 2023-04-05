// Program to find pair of given sum ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Prints vector elements
void printVector(vector<int> vec){
    for(auto val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}

// #1 - Function to find pair of given sum ~ O(n*n) & O(1)
vector<int> findPair1(vector<int> vec, int sum){
    // Iterate vector till end
    for(int i=0; i<vec.size(); i++){

        // Check sum exist or not from each element
        for(int j=i+1; j<vec.size(); j++){    
            if(vec[i]+vec[j] == sum){
                return {i, j};
            }

        }
    }
    return {-1, -1};
}

// #2 - Function to find pair of given sum ~ O(n) & O(n)
vector<int> findPair2(vector<int> vec, int sum){
    unordered_map<int, int> hashMap; // Create a map

    // Iterate vector till end
    for(int i=0; i<vec.size(); i++){

        // Return indeces if pair found
        if(hashMap.count(sum-vec[i]))
            return {hashMap[sum-vec[i]], i};

        // Insert current element as key with its index as value in map
        hashMap[vec[i]] = i;

    }
    return {-1, -1};
}

// Driver code
int main(){
    vector<int> vec{1, 2, 3, 4};
    printVector(vec);
    int sum = 7;

    // Function call
    vec = findPair2(vec, sum);
    printVector(vec);

    return 0;
}