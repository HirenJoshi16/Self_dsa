// Program to find maximum width of columns of a grid ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// Method to print grid
void printGrid(vector<vector<int>> grid){
    for(auto row : grid){
        for(auto val : row)
            cout<<val<<" ";
        cout<<'\n';
    }
    cout<<"\n";
}

// Method to find maximum width of columns of given grid - O(M*N) & O(N)
vector<int> maxWidthOfColumn(vector<vector<int>>& grid){
    int m = grid.size(); // Represents row
    int n = grid[0].size(); // Represents column
    vector<int> ans(n, 0); // Stores result

    for(int j=0; j<n; j++){
        int maxWidth = 0; // To track max width for each column

        for(int i=0; i<m; i++){
            int width = 0;
            // When current element is 0 
            if(grid[i][j] == 0){
                width = 1;
            } 
            // When current element is not 0 
            else{
                stringstream ss; 
                ss << grid[i][j]; // ss object takes the copy of current element
                width = ss.str().size(); // First it converts it to string than it finds the size of it
            }
            maxWidth = max(width, maxWidth); // Take the maximum width
        }
        
        ans[j] = maxWidth; // Store the max width for current column
    }

    return ans;
}

// Method to print column width
void printWidth(vector<int> columnWidth){
    for(auto currWidth : columnWidth)
        cout<<currWidth<<" ";

    cout<<'\n';
}

// Driver code
int main(){
    vector<vector<int>> grid = {{-15, 1, 3},
                                {15, 7, 12},
                                {25, 6, -2}};
    printGrid(grid);

    // Method call
    vector<int> columnWidth = maxWidthOfColumn(grid);
    cout<<"Maximum width of columns : ";
    printWidth(columnWidth);
    
    return 0;
}
// Link: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/