// Program to find common elements from all rows in matrix
#include <iostream>
#include <iterator >
#include <map>
using namespace std;

// Function to find common element from all rows ~ O(n*m) & O(n)
bool findCommon(int A[3][3]){
    // Initializing map
    map<int, int> mp;

    // Edge case
    if(!A)
        return false;

    // Insert elements of 1st row to map
    for(int j=0; j<3; j++)
        mp[A[0][j]] = 1;

    // Traverse the matrix
    for(int i=1; i<3; i++){

        for(int j=0; j<3; j++){
            // If element is present in the map and is not duplicated in current row
            if(mp[A[i][j]] == i){
                // Increment count of the element in map by 1
                mp[A[i][j]] = i+1;

                // If its last row 
                if(i==2 && mp[A[i][j]] == 3){
                    cout<<A[i][j]<<" ";
                }
            }
        }
    }
    return true;
}

// Driver code
int main(){
    int A[3][3];
    // Input matrix
    cout<<"Enter Matrix : "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>A[i][j];
        }
    }

    cout<<endl;
    if(findCommon(A)){
        cout<<": is the common value";
    }
    else{
        cout<<"no common found";
    }
    return 0;
}
