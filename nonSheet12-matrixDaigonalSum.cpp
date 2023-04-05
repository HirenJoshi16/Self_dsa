// Program to find daigonal sum in matrix - coded by vHiren
#include <iostream>
using namespace std;
const int n=3;
const int m=3;

// Function to find daigonal sum ~ O(n) & O(1)
long daigonalSum(int A[n][m]){
    // Edge case
    if(!A)
        return 0;

    long sum = 0;
    // Iterate n times
    for(int i=0; i<n; ++i){
        sum += A[i][i] + A[i][n-i-1];
    }   

    // If total rows are odd then difference this - A[n/2][n/2] - element from sum
    if(n%2) {
        sum -= A[n/2][n/2];
    }
    return sum;
}

// Driver code
int main(){
    int A[n][m];
    // Input matrix
    cout<<"Enter Matrix : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }

    // Function call
    if(long sum = daigonalSum(A)){
        cout<<endl<<sum;
    }
    else{
        cout<<"Matrix undefined!";
    }
    return 0;
}