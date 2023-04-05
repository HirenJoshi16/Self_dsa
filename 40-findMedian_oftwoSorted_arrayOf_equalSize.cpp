#include <bits/stdc++.h>
using namespace std;

// Finds median of two sorted array of equal size ~ O(n) & O(1)
// Can also be done in O(logn) & O(1)
int findMedian(int *A, int *B, int n){
    int i = 0; // Tracks A[] current index  
    int j = 0; // Tracks B[] current index
    int prevVal = -1; // Stores prev median value in loop
    int currVal = -1; // Stores current median value in loop
    int count;

    /* Since there are 2n elements, 
    median will be average of elements 
    at index n-1 and n in the array 
    obtained after merging ar1 and ar2 */
    for(count = 0; count <= n; count++){
        
        /* In case where 
           all elements of A[] are
           smaller than smallest(or first)
           element of B[], hence break the loop*/
        if(i == n){
            prevVal = currVal;
            currVal = B[0];
            break;
        }

        /* In case where 
           all elements of B[] are
           smaller than smallest(or first)
           element of A[], hence break the loop*/
        else if(j == n){
            prevVal = currVal;
            currVal = A[0];
            break;
        }
        /* equals sign because if two 
           arrays have some common elements */
        if(A[i] <= B[j]){
            prevVal = currVal;
            currVal = A[i];
            i++;
        }
        else{
            prevVal = currVal;
            currVal = B[j];
            j++;
        }
    }
    return (prevVal + currVal)/2;
}

// Driver code
int main(){
    int A[] = {1, 12, 15, 26, 38};
    int B[] = {2, 13, 17, 30, 45};
    int n = 5;
    int median;

    (median = findMedian(A, B, n)) ? cout<<"Median is : "<<median : cout<<"Median invalid";
    return 0;
}