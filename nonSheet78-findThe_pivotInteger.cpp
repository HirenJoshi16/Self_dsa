// Program to find pivot integer ~ coded by Hiren
#include <iostream>
using namespace std;

// Method to find pivot integer - O(N) & O(1)
int pivotInteger(int n){
    int totalSum = 0;
    for(int i = 1; i <= n; i++)
        totalSum += i;

    int rightSum = 0;
    for(int i = n; i > 0; i--){
        rightSum += i;
        if(rightSum == totalSum)
            return i;
        totalSum -= i;
    }

    return -1;
}

// Driver code
int main(){
    int n = 8;
    // Method call
    int pivotVal = pivotInteger(n);
    cout<<"The pivot integer of "<<8<<" is "<<pivotVal;
    
    return 0;
}