// Program to break given palindrome string such resulting string is not a palindrome ~ coded by Hiren
#include <iostream>
#include <cstring>
using namespace std;

// Method to break given palindrome string such resulting string is not a palindrome - O(N) & O(1)
string breakPalindrome(string palindrome){
    int n = palindrome.size();
    // Edge case
    if(n == 1) 
        return ""; // Its noticed that a string with single character is always a palindrome whether we replace it or not

    // N/2 Because we know a palindrome string's mirror side is always a palindrome so no need to see the other side
    for(int i=0; i<n/2; i++){  
        // When current character is not 'a'
        if(palindrome[i] != 'a'){
            palindrome[i] = 'a'; // Replace it with 'a'
            return palindrome;
        }
    }

    palindrome[n-1] = 'b'; // If we are here such means all the character in string is 'a' than the smallest lexographically character remains is 'b'
    return palindrome;
}

// Driver code
int main(){
    string palindrome = "abcba";
    cout<<palindrome;

    // Method call
    palindrome = breakPalindrome(palindrome);
    cout<<'\n'<<palindrome;
    
    return 0;
}
// Link: https://leetcode.com/problems/break-a-palindrome/description/