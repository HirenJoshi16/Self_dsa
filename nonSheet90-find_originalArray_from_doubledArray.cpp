// Program to find original array of given doubled array ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

// Method to print given array
void printArray(vector<int> changedArray){
    for(auto val : changedArray)    
        cout<<val<<" ";
        
    cout<<'\n';
}

// Method to find original array of given doubled array - O(NLogN) & O(N)
vector<int> findOriginalArray(vector<int>& changedArray){
    int n = changedArray.size();
    if(n%2 != 0) // Its observed that, If each element twice has to be present than its must for doubled array to be of even size
        return {};
        
    sort(changedArray.begin(), changedArray.end()); // Requires to easily take twice of each element, Consider this -> {1, 6, 4, 3} Here 6 requires an extra check such as currVal/2 presents in map. Because 3 is not before 6 here, This also works! 

    unordered_map<int, int> hashMap;
    for(auto val : changedArray)
        hashMap[val]++; // Store the value with its frequency

    vector<int> ans; // Stores result
    for(auto currVal : changedArray){
        int currValTwice = currVal*2; // Take twice of current element

        if(hashMap[currVal] == 0) // It means the current element is an twice, And its seen for another element
            continue; 

        else if(!hashMap.count(currValTwice) || hashMap[currValTwice] == 0) // If current element twice is not present or In case it presents but not for current element
            return {};

        else
            ans.push_back(currVal); // Twice of current element found correctly 
        
        hashMap[currVal]--; // Decrement because the twice is found for current element
        hashMap[currValTwice]--; // And each element can have its own single twice
    }
    return ans;
}
// Note: Sorting can be avoided if extra check for current element is added correctly of seing for its twice is present in map

// Driver code
int main(){
    vector<int> changedArray{1, 3, 4, 2, 6, 8};
    printArray(changedArray);

    // Method call
    vector<int> originalArray = findOriginalArray(changedArray);
    printArray(originalArray);

    return 0;
}
// Link: https://leetcode.com/problems/find-original-array-from-doubled-array/description/