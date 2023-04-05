//Implemented by Hiren
#include <iostream>
using namespace std;

//Function that reverses string 
void reverse(string *A, int n){
    int j=0;
    string tmp;
    for(int i=n; i>n/2; i--){
        tmp = A[n-j-1];
        A[n-j-1] = A[j];
        A[j] = tmp;
        j++;
    }
}

//Shows the elements
void printArray(string *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    string A[] = {"H", "I", "R", "E", "N", "J", "O", "S", "H", "I"};
    int n = 10;
    
    printArray(A, n);
    cout<<endl;
    reverse(A, n);
    printArray(A, n);
    return 0;
}