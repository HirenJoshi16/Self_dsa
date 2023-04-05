//Condition ~ in O(n) time && O(1) space
#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

void sort(int A[], int l, int h){
    int m = l;
    int tmp;

    while(m<h){
        if(A[m] == 1){
            m++;
        }
        if(A[m] == 0){
            tmp = A[m];
            A[m] = A[l];
            A[l] = tmp;
            m++;
            l++;
        }
        else if(A[m] == 2){
            tmp = A[m];
            A[m] = A[h];
            A[h] = tmp;
            h--;
        }
    }
}

int main(){
    // int A[] = {0, 1, 2, 0, 1, 2};
    int A[] = {0, 1, 2, 0, 1, 2, 1, 0, 0, 1, 2};
    int n=11;
    printArray(A, n);
    cout<<endl;
    sort(A, 0, n-1);
    printArray(A, n);
    return 0;
}