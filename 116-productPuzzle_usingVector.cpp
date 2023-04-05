// Logic & coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Finds product of A[i] except A[i] itself ~ O(n) & O(n)
vector<long long int> findProduct(vector<long long int>& myVec, int n){
    vector <long long int> vec;

    long product=1;
    long zeroCount=0;

    // When array is 0 sized
    if(n<=0){
        return vec;
    }
        // Iterate the array
        for(int i=0; i<n; i++){
            // Calculate the total product with handling zeros
            myVec[i] != 0 ? product *= myVec[i] : zeroCount++;
        }
        
        // Iterate myVec & push elements to vec by conditions
        for(int i=0; i<n; i++){
            if(zeroCount > 1){
            // Push when two values in myVec are zero
                vec.push_back(0);
            }
            else if(zeroCount < 1){
            // Push when no value in myVec is zero
                vec.push_back(product/myVec[i]);
            }
            else if(zeroCount == 1 && myVec[i] != 0){
            // Push when one value in myVec is zero if current value is not zero
                vec.push_back(0);
            }
            else{
            // Push when one value in myVec is zero
                vec.push_back(product);
            }
        }
    return vec;
}

// Driver code
int main(){
    // Initializing vector
    vector<long long int> myVec{4, 6, 3, 2, 10};
    int n = myVec.capacity();

    // Function call
    vector<long long int> vec = findProduct(myVec, n);
    // Printing vector elements
        for(auto i : vec){
            cout<<i<<" ";
        }

    return 0;
} 