// Program to spirally traverse a matrix - coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Creates matrix by user input
vector<vector<int>> inputMatrix(vector<vector<int>> mat, int row, int col){
    cout<<"Enter Matrix : "<<endl; 

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>mat[i][j];
        }
    } cout<<endl;
    return mat;
}

// Traverses matrix spirally - O(row*col) & O(spiral.size())
vector<int> spiralTraversal(vector<vector<int>> mat, int row, int col){
    vector<int> spiral; // Create a vector to store result 
    
    // Tracks column
    int left = 0; int right = matrix[0].size()-1;
        
    // Tracks row
    int top = 0; int bottom = matrix.size()-1;

    // Iterate whole matrix
    while(top <= bottom && left <= right){
        // Traverse first row from remaining
        for(int i=left; i<=right; i++){
            spiral.push_back(mat[top][i]);
        }
        top++;

        // Traverse last column from remaining
        for(int i=top; i<=bottom; i++){
            spiral.push_back(mat[i][right]);
        }
        right--;

        // Traverse last row from remaining
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                spiral.push_back(mat[bottom][i]);
            }
        }
        bottom--;

        // Traverse first column from remaining  
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                spiral.push_back(mat[i][left]);
            }
        }
        left++;
    }
    return spiral;
}

// Driver code
int main(){
    int row = 4; int col = 4;

    vector<vector<int>> mat(row, vector<int> (col)); // Create 2d vector
    mat = inputMatrix(mat, row, col);

    // Function call
    vector<int> ans = spiralTraversal(mat, row, col);
    for(auto val : ans){
        cout<<val<<" ";
    }

    return 0;
}