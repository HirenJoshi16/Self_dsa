// Program to find duplicates in an array of characters ~ T.C - O(n*logn), S.C - O(1)
#include <bits/stdc++.h>
using namespace std;

// Shows the element
void printString(string str){
        for(auto s : str){
        cout<<s;
        }
}

// Finds duplicates to string ~ Hiren's code
void findDuplicates(string A){
    int count;
    sort(A.begin(), A.end());

    for(int i=0; i<A.length(); i++){
        count = 1;
            if(A[i+1] == A[i] && A[i] != A[i-1]){
                count = 0;
            }
            if(count == 0){
                cout<<A[i]<<" ";
        }
    }
}

int main(){
    string str = "geeksforgeeks";
    printString(str);
    
    cout<<"\nDuplicate elements are : ";
    findDuplicates(str);
    return 0;
} 