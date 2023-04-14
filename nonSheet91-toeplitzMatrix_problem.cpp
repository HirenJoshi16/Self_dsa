// Program to verify given matrix is a toeplitz or not ~ coded by Hiren
#include <iostream>
#include <vector>
using namespace std; 

// Method to print given matrix
void printMatrix(vector<vector<int>> matrix){
    for(auto row : matrix){
        for(auto val : row)
            cout<<val<<" ";
        cout<<'\n';
    }    
}

// Method to verify given matrix is a toeplitz or not - O(N*N) & O(1)
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    // There is no previous daigonal for elements of 0th row & 0th column hence start from 1st
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(matrix[i][j] != matrix[i-1][j-1]) // Check current element is equal to its previous daigonal
                return false;
        }
    }
    return true;
}

// Driver code
int main(){
    vector<vector<int>> matrix{{1, 2, 3, 4}, 
                               {5, 1, 2, 3}, 
                               {9, 5, 1, 2}};
    printMatrix(matrix);

    // Method call
    if(isToeplitzMatrix(matrix))
        cout<<"Given matrix is a toeplitz";
    else
        cout<<"Given matrix is a not toeplitz";

    return 0;
}