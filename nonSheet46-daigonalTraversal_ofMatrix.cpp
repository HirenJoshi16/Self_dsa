// Program to daigonally traverse a matrix ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Routine to create matrix by user input
vector<vector<int>> inputMatrix(vector<vector<int>> mat, int row, int col){
    cout<<"Enter Matrix : "<<endl; 

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>mat[i][j];
        }
    } cout<<endl;
    return mat;
}

// Routine to traverse matrix daigonally - O(n) & O(n)
vector<int> zigZagTraversal(vector<vector<int>> mat, int row, int col){
    vector<int> ans(row*col); // Create a vector of size (row*col)

    int n = ans.size();
    int r = 0;
    int c = 0;

    // Iterate each value
    for(int i=0; i<n; i++){
        ans[i] = mat[r][c]; // Store current value

        // When index is even we have to go up
        if((r + c)%2 == 0){
            // If current column is the last column then move to the next row - First check because it may possible that the matrix is of 1 column
            if(c == col-1){
                r++;
            }
            // If at first row then move to next column
            else if(r == 0){
                c++;
            }
            // When in between the matrix move to the previous row and to next column 
            else{
               r--;
               c++; 
            }   
        }
        // When index is odd we have to go down
        else{
            // If current row is the last row then move to the next column - First check because it may possible that the matrix is of 1 row 
            if(r == row-1){
                c++;
            }
            // If at first column then move to next row
            else if(c == 0){
                r++;
            }
            // When in between the matrix move to the next row and to previous column 
            else{
               r++; 
               c--;
            }
        }
    }
    return ans;
}

// Driver code
int main(){
    int row = 3; int col = 3;

    vector<vector<int>> mat(row, vector<int>(col)); // Create a 2d vector
    mat = inputMatrix(mat, row, col);
    
    // Routine call
    vector<int> ans = zigZagTraversal(mat, row, col);
    for(auto val : ans)
        cout<<val<<" ";

    return 0;
}