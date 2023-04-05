// Program to verify each element has unique occurrence or not ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to verify unique occurrences present or not - O(n) & O(n)
bool uniqueOccurrences(vector<int>& arr){
    // Edge case
    if(arr.size() <= 0) return false;

    unordered_map<int, int> hashMap;
    unordered_set<int> hashSet;
    
    // Store each element with its frequency
    for(int i=0; i<arr.size(); i++){
        hashMap[arr[i]]++;
    }
        for(auto it : hashMap){
            // If duplicate exist
            if(hashSet.count(it.second)) 
                return false;
            hashSet.insert(it.second);
        }
        
    return true;
}

// Driver code
int main(){
    vector<int> arr{1, 2, 2, 1, 1, 3, 4};

    // Method call
    if(uniqueOccurrences(arr))
        cout<<"Unique occurrences present";
    else
        cout<<"Unique occurrences not present";

    return 0;
}