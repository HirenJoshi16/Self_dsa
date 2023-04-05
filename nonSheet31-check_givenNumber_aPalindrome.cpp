// Program to check given number is palindrome or not ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Method to check given number is palindrome or not - O(logn) & O(1)
bool isPalindrome(int x) {
    // When input is negative
    if(x<0) return false;

    int val = 10;
    int tmp = x; // At last actual value will needed hence take copy 
    long long palindromeVal = 0; // To store palindrome of x
    palindromeVal = (palindromeVal * val) + x % val; // Store remainder value
    
        // Store palindrome of x
        while (tmp / val != 0){
            tmp = tmp / val;
            palindromeVal = (palindromeVal * val) + tmp % val;
        }

    return (palindromeVal == x ? true : false);
}

// Driver code
int main(){
    int num = 121;

    // Method call
    if(isPalindrome(num))
        cout<<num<<" is palindrome";
    else
        cout<<num<<" is not palindrome";

    return 0;
}

// The time complexity of the code is O(log n), which means the time taken by the code to run increases logarithmically with the input size 'x'.
// Therefore, the time complexity of this code is proportional to the number of digits in the input 'x', which is log base 10 of n. That's why we say the time complexity of this code is O(log n)

// 𝗧𝗶𝗺𝗲 𝗰𝗼𝗺𝗽𝗹𝗲𝘅𝗶𝘁𝘆 : 𝗢(𝗟𝗼𝗴𝗡)
// 𝗥𝗲𝗮𝘀𝗼𝗻 : This is because the number of digits in the input integer x determines the number of iterations in the while loop, and the number of digits in an integer is proportional to its logarithm in base 10 (or any other base).
// In this implementation, base 10 is used because the numbers in the input x are in base 10 (decimal) notation. Hence, it's easier to work with the same base rather than converting the numbers to a different base.

// 𝗘𝘅𝗮𝗺𝗽𝗹𝗲 : Let x = 121
// When x = 121, the while loop will run for log10(121) = 2 times, since the number of digits in 121 is 3. Therefore, the time complexity of this code for x = 121 will be O(logn) = O(log10(121)) = O(2)

// 𝗬𝗼𝘂𝗿 𝗤𝘂𝗲𝘀𝘁𝗶𝗼𝗻 : That means the while loop always run proportional to no of digits in the integer x ?
// And the answer is BINGO, YES!