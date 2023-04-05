// Program to find smallest missing positive integer in an unsorted array ~ coded by vHiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to print vector elements
void printVector(vector<int> A){
    for(auto val : A)
        cout<<val<<" ";
    cout<<endl;
}

// #1 Method to find first missing positive integer - O(N*Log(N)) & O(1)
int firstMissingPositive_1(vector<int>& A){
    sort(A.begin(), A.end()); // Sort the vector
    int ans = 1;

    for(int i = 0; i < A.size(); i++){
        // If equal, than current value is not our missing integer hence check for the next one
        if(A[i] == ans)
            ans++; // Increment to check for the next one
    }

    return ans;
}

// #2 Method to find first missing positive integer - O(N) & O(1)
int firstMissingPositive(vector<int>& A){
    int n = A.size();

    for(int i = 0; i < n; i++){
        // When current value is negative or greater than N then no swap required
        // When current value is neither negative nor greater than N then swap required to set current value to its correct index
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);
    }
    
    // Iterate and do nothing when current value maps to its index 
    for(int i = 0; i < n; i++){
        // If current value does not map to its index than missing integer will be i+1
        if(A[i] != i + 1)
            return i + 1;
    }
    
    return n + 1; // When all elements are at correct index
}

// Driver code
int main(){
    vector<int> A{3, 2, 0, 5, 4};
    printVector(A);

    // Method call
    int smallestMissingPositive = firstMissingPositive(A);
    cout<<"First missing positive integer is : "<<smallestMissingPositive;

    return 0;
}
