// Program to verify there exist two integers whose square sum equals given (non negative integer) N or not ~ coded by vHiren
#include <iostream>
#include <cmath>
using namespace std;

// #1 Method to check there exist two integers whose square sum equals given n or not - O(n*n) & O(1)
bool judgeSquareSum(int n){ 
    // Edge case
    if(n == 0 || n == 1)
        return true;

    // Generate and check each square combination 
    for(long i = 1; i*i <= n; i++){

        for(long j=1; j*j <= n; j++){
            if(i*i + j*j == n)  
                return true;
        }

    }
    return false;
}

// #2 Method to check there exist two integers whose square sum equals given n or not - O(sqrt(n)) & O(1)
bool judgeSquareSum2(int n) {
    // Edge case
    if(n == 0 || n == 1)
        return true;

    long a = 0; 
    long b = sqrt(n); // As we know, we always have a and b in between or equal to this range value : 0 to sqrt(n)

        while(a <= b){
            long long squareSum = (a*a) + (b*b);

            // If given n is a perfect square then it returns true, always in the first iteration and overall time taken will be constant O(1) as no further executions needed
            if(squareSum == n)
                return true;

            // If sum of squares is lesser, than current value of a is not possible
            else if (squareSum < n)   
                a++;
            
            // When sum of squares is greater, than current value of b is not possible
            else    
                b--;
        }

    return false;
}

// #3 Method to check there exist two integers whose square sum equals given n or not - O(sqrt(n)) & O(1)
bool judgeSquareSum3(int n) {
    // Edge case
    if(n == 0 || n == 1)
        return true;

        for(long i=0; i <= sqrt(n); i++){
            long long a = i*i; 
            long long b = n - a;

            long long sqrt_b = sqrt(b);

            // If given n is a perfect square then it returns true, always in the first iteration and overall time taken will be constant O(1) as no further executions needed
            if(sqrt_b * sqrt_b == b)
                return true;
        }

    return false;
}

// Driver code
int main(){
    int n = 20;

    // Method call
    if(judgeSquareSum(n))
        cout<<"Sum of two squares exist equal to : "<<n;
    else
        cout<<"Sum of two squares does not exist";

    return 0;
}