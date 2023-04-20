// Program to find row with maximum number of ones in given matrix ~ coded by Hiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print matrix
void printMatrix(vector<vector<int>> mat){
    for(auto row : mat){
        for(auto val : row)
            cout<<val<<" ";
        cout<<'\n';
    }
    cout<<"\n";
}

// Method to find row with maximum number of ones - O(M*N) & O(1)
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat){
    int m = mat.size(); // Represents row
    int n = mat[0].size(); // Represents column
    vector<int> ans(2, 0); 
    
    for(int i=0; i<m; i++){
        
        int count = 0;
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1) // When current element is 1
                count++;
        }
        if(count > ans[1]){ // When there are multiple rows with same count than store the minimum row
            ans[0] = i; // Store the row
            ans[1] = count; // Store the count
        }
        
    }
    return ans;
}

// Method to print column width
void printVector(vector<int> ans){
    for(auto val : ans)
        cout<<val<<" ";

    cout<<'\n';
}

// Driver code
int main(){
    vector<vector<int>> mat = {{0, 1, 0},
                               {1, 1, 0},
                               {0, 1, 1}};
    printMatrix(mat);

    // Method call
    vector<int> ans = rowAndMaximumOnes(mat);
    printVector(ans);
    
    return 0;
}
// Link: https://leetcode.com/contest/weekly-contest-341/problems/row-with-maximum-ones/