//Implemented by Hiren
#include <iostream>
using namespace std;

//Function that reverses array
void reverse(int *A, int n){
    int j=0;
    int tmp;
    for(int i=n; i>n/2; i--){
        tmp = A[n-j-1];
        A[n-j-1] = A[j];
        A[j] = tmp;
        j++;
    }
}

//Shows the elements
void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    
    printArray(A, n);
    cout<<endl;
    reverse(A, n);
    printArray(A, n);
    return 0;
}