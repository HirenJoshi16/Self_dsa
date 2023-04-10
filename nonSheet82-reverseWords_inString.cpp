// Program to reverse words in a string ~ coded by vHiren
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;

// #1 Method to reverse words in a given string - O(S) & O(1)
string reverseWords_1(string s){
    // By default stringstream tokenizes on space character -> ' '
    stringstream stringToken(s); // Creating a instance named stringToken of stringstream class, Its constructor takes the given string and tokenize each word
    string token = ""; // Later use: To take each token(word)

    string ans = ""; // To store result string

    // Extract each token(word) from stringToken object and store them into token variable one at a time
    while(stringToken >> token)
        ans = token + ' ' + ans; // Concate each word in ans

    return ans.substr(0, ans.length()-1); // Length-1 to avoid the space at last, Inside it
}
// Note: Above way is known as Tokenization

// #2 Method to reverse words in a given string - O(S) + O(R/2) --> O(S) Time & O(1) Space
string reverseWords_2(string s){
    // Reverse the whole string
    reverse(s.begin(), s.end()); // Method uses swap for reverse
    
    int n = s.length();
    int i = 0; // Tracks each character
    int l = 0; // Tracks start position of a word
    int r = 0; // Tracks end position of a word
    
    while(i < n){
        while(i < n && s[i] != ' '){
            // Assign character of ith position to rth position and than increment
            s[r++] = s[i++]; // Same as --> r++; i++;
        }
        // When correct position for l and r get setted, Reverse the current word
        if(l < r){
            reverse(s.begin()+l, s.begin()+r);
            s[r] = ' '; // Leave a space after reversal of current word
            r++; // Than increment rth position to continue
            l = r; // Assign l to current position of r
        }
        i++;
    }

    s = s.substr(0, r-1); // At last a space is leaved after last word of the string hence r-1
    return s;
}

// Driver code
int main(){
    string s = "    Hiren is a    good boy  "; cout<<s;
    // Method call
    s = reverseWords_1(s);
    cout<<endl<<s;
    
    return 0;
}
// Link: https://leetcode.com/problems/reverse-words-in-a-string/