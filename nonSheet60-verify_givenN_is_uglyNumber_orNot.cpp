// Program to verify given N is ugly number or not ~ coded by vHiren
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5
#include <iostream>
using namespace std;

// Method to verify given N is ugly or not - O(LogN) & O(1)
bool isUgly(int n){
    while(n > 1){
        // If its divisible by 2 
        if(n%2 == 0)
            n /= 2; // Store the quotient
            
        // If its divisible by 3
        else if(n%3 == 0)
            n /= 3;

        // If its divisible by 5 
        else if(n%5 == 0)
            n /= 5;

        // If its not divisible from 2, 3, 5
        else break;
    }

    return (n==1); // Remains 1 if given N is ugly number
}

// Driver code
int main(){
    int n = 20; cout<<"n : "<<n<<endl; 

    // Method call
    if(isUgly(n))
        cout<<n<<" is a ugly number";
    else
        cout<<n<<" is not a ugly number";
    
    return 0;
}
