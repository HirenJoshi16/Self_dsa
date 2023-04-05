// Program to reverse given signed 32 bit-integer x ~ coded by vHiren
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0. Assume the environment does not allow you to store 64-bit integers (signed or unsigned)
#include <iostream>
#include <climits>
using namespace std;

// Method to reverse given integer x - O(logX) & O(1)
int reverseInteger(int x){
    int revDigit = 0;
    
    while(x != 0){
        int remVal = x%10;
        if(revDigit > INT_MAX/10 || revDigit < INT_MIN/10) // Case when overflow occurs
            return 0;

        revDigit = (revDigit*10) + remVal; // Build the reverse
        x /= 10; 
    }

    return revDigit;
}

// Driver code
int main(){
    int x = 123; cout<<"x : "<<x<<endl; 

    // Method call
    cout<<"reverse : "<<reverseInteger(x);
    
    return 0;
}
