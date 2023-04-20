// Program to to find count of columns that are not sorted lexicographically ~ coded by Hiren
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Method to print vector 
void printVector(vector<string> strs){
    for(auto ch : strs)
        cout<<"\""<<ch<<"\"  ";
        
    cout<<'\n';
}

// Method to find count of columns that are not sorted lexicographically - O(N*K) & O(1)
int minDeletionSize(vector<string>& strs){
    int n = strs.size();
    int k = strs[0].size();
    int columnCount = 0; // Tracks number of columns to be deleted

    for(int i = 0; i < k; i++){ // Iterate each string length
        for(int j = 1; j < n; j++){ // Iterate all the N strings of array
            if(strs[j][i] < strs[j-1][i]){ // Compare each letter
                columnCount++;
                break;
            }
        }
    }

    return columnCount;
}

// Driver code
int main(){
    vector<string> strs{"cba","daf","ghi"};
    printVector(strs);

    // Method call
    int columnCount = minDeletionSize(strs);
    cout<<"The number of columns to be deleted is : "<<columnCount;

    return 0;
}
// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/