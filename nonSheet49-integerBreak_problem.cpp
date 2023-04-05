// Program to find maximum product by breaking given integer N into the sum of k(k >= 2) positive integers ~ coded by vHiren
#include <iostream>
using namespace std;

// Method to find maximum product by breaking given n - O(logn) & O(1)
int findMaxProduct(int n){
    // Edge case
    if(n == 2 || n == 3)
        return n-1;

    int ans = 1; // Stores result
    
    // N > 4 as because we know for values greater than 4 will always have maximum product when the part size contain 3's 
    while(n > 4){
        n -= 3; // Reduce part size 3 each time
        ans *= 3; // Multiply part size 3 each time
    }
    
    // If given N > 4 than At the end(after loop ends) N will be the value, which is the last remaining value in whole part size Or the value after the last 3 of 3's
    // e.g --> Let N = 14, the integer break that sums to N will be : 3 + 3 + 3 + 3 + 2 = 14 
    // The product of this break gives the maximum product for N = 14

    // For comprehension, as the (ans*3) computed each time, then when the loop ends, if you notice the number of multiplication of 3's done are exactly same to the number of 3's here --> (3 + 3 + 3 + 3) + 2 = 14, So at the end N will remain exactly same as that last value which is 2 in this case
    // For verification you can add all of 3's computed as (ans*3) with value of N at the end(after loop ends), This will sum exactly to given N 
    
    return (ans * n);
}

// Driver code
int main(){
    cout<<"Maximum product is : "<<findMaxProduct(18);
    return 0;
}

// The time complexity of the approach that involves breaking down the integer n into parts of size 3 whenever possible and using 2 instead of 3 for any remaining parts is O(log n).

// The reason is that the algorithm works by repeatedly dividing the input n by 3 and multiplying the result by 3, except for the last part that may be smaller than 3. Therefore, the number of times n is divided by 3 is proportional to the logarithm of n to the base 3. Specifically, the number of iterations required is ceil(log3(n)), where ceil(x) is the smallest integer greater than or equal to x.

// Each iteration of the algorithm takes constant time. Therefore, the time complexity of the algorithm is proportional to the number of iterations, which is O(log n) in this case.