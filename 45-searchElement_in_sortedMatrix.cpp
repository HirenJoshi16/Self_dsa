// Program to search element in sorted matrix - coded by vHiren
#include <iostream>
using namespace std;

// Finds element in matrix ~ Best Approach - O(n+m) & O(1)
bool findinMatrix(int A[][4], int findVal){
    int row=0, col=3;
    int val = A[row][col];

        // Iterate total rows + 1 time ~ for Worst case possibility
        for(int k=0; k<=3+1; k++){
            val = A[row][col];

            if(val == findVal)
                return true;
            
            else if(val < findVal)
                row++;
            
            else
                col--;

        }
    return false;
}

// Driver code
int main(){
    int A[3][4];
    // Input matrix
    cout<<"Enter Matrix : "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>A[i][j];
        }
    }
    // User input
    int element;
    cout<<"\nEnter valment : ";
    cin>>element;

    // Function call
    if(findinMatrix(A, element)){
        cout<<"element found";
    }
    else{
        cout<<"element not found";
    }
    
    return 0;
}