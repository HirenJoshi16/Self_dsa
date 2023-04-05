// Program to daigonally traverse a matrix 2 ~ coded by vHiren
// Note : Column size for each row can differ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Routine to create matrix by user input
vector<vector<int>> inputMatrix(vector<vector<int>> mat){
    cout<<"Enter Matrix : "<<endl; 

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cin>>mat[i][j];
        }
    } cout<<endl;
    return mat;
}

// #1 Routine to traverse matrix daigonally - O((row*col) log(row*col)) & O(row*col)
// O(row*col * log(row*col)) --> It is the same as O(nlogn). In this case, n refers to the total number of elements in the matrix, which is equal to rowcol
vector<int> zigZagTraversal(vector<vector<int>> mat){
    // Edge case
    if(mat.empty() || mat[0].empty())
        return {};   

    int n = mat.size();
    vector<vector<int>> daigonalMat; // Create a 2d vector

    // Iterate input matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<mat[i].size(); j++)
            // Store indeces for daigonals and element with its column number as in the daigonal matrix we need columns too to access values
            daigonalMat.push_back({i+j, j, mat[i][j]});
    }

    // Sort the daigonal matrix indeces or row and column numbers to set matrix correctly
    sort(daigonalMat.begin(), daigonalMat.end());
    
    vector<int> ans;
    // Iterate and store result values
    for(int i=0; i<daigonalMat.size(); i++)
        ans.push_back(daigonalMat[i][2]);

    return ans;
}
// Self Tip : Daigonal matrix indeces are row numbers to be stored or i+j for each daigonal to store row number for daigonal matrix

// Driver code
int main(){
    vector<vector<int>> mat(3, vector<int>(3)); // Create a 2d vector
    mat = inputMatrix(mat);
    
    // Routine call
    vector<int> ans = zigZagTraversal(mat);

    // Print result values
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}

// The time complexity of the first nested loop in the zigZagTraversal function is O(n^2), where n is the maximum of row and column size. Therefore, the overall time complexity of the zigZagTraversal function is O(n^2 + n log n), but since O(n^2) is dominated by O(n log n) for large n, we can simplify the time complexity to O(n log n)

// Reason being O(nlogn) : We can say that O(n^2) is dominated by O(n log n) if, for sufficiently large n, the growth rate of O(n log n) is faster than the growth rate of O(n^2). This is because for large enough n, the additional cost of the O(n log n) operation (sorting) becomes more significant than the cost of the O(n^2) operation (nested loop). In other words, as n grows larger and larger, the number of iterations in the nested loop becomes less significant compared to the cost of sorting. Therefore, we can say that the time complexity is dominated by the sorting operation, which has a faster growth rate of O(n log n)