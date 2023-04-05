// Program to rotate matrix by 90 degress ~ coded by vHiren
#include <bits/stdc++.h>
#define n 3
using namespace std;

// Displays matrix elements
void printMatrix(int mat[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

// #1 - Function to rotate matrix by 90 degress ~ O(n*n) & O(1)
void rotateMatrixClockwise1(int mat[n][n]){
    // Edge case
    if(!mat) return;

    // Print the elements directly
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--)
            cout<<mat[j][i]<<" ";
        cout<<endl;
    }
}

// #2 - Function to rotate matrix by 90 degress ~ O(n*n) & O(1)
void rotateMatrixClockwise2(int mat[n][n]){
    // Edge case
    if(!mat) return;

    // Transpose the matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            swap(mat[i][j], mat[j][i]);
    }

    // Reverse each row
    for(int i=0; i<n; i++){
        int low = 0; int high = n-1;
        // Swap current row elements
        while(low < high){
            swap(mat[i][low], mat[i][high]);
            low++; high--;
        }
    }
}

// Driver code
int main(){
    int mat[n][n] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    printMatrix(mat); cout<<endl;

    // Function call
    rotateMatrixClockwise2(mat);
    printMatrix(mat);

    return 0;
}