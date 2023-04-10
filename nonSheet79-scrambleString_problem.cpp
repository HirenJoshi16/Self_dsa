// Program to verify given second string is a scrambled version of first string or not ~ coded by vHiren
#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> hashMap;

// Method Helper: Compares both the string
bool compareStrings(string s1, string s2){
    // If both strings are equal return true, Remember not in length
    if(s1 == s2)
        return true;
    // If both string are not equal in size return false, Remember here we're talking about length
    if(s1.length() != s2.length())
        return false;

    string key = s1 + "and" + s2; // Used for memoization --> Store current compared version of s1 and s2
    // When the same compared version founds than no need to recompute, Simply store the current one and return
    if(hashMap.find(key) != hashMap.end())
        return hashMap[key];

    bool ans = false; // Initially we know s2 is not scrambled version of s1
    int n = s1.length();
    // No need to consider i=0, As we have discussed when the size of s1 and s2 is equal simply return true
    for(int i = 1; i < n; i++){
        // Check is scrambled, from swapping the left and right part of s1  
        // After swap           // Compare left part of s1 to s2
        bool scramblesBySwap = compareStrings(s1.substr(i, n-i), s2.substr(0, n-i))
                                            && 
                                // Compare right part of s1 to s2
                               compareStrings(s1.substr(0, i), s2.substr(n-i, i));
        // When its scrambled by swap    
        if(scramblesBySwap){
            ans = true;
            break;
        }

        // Check is scrambled, By using no swap of left and right part of s1  
        // Without swap           // Compare left part of s1 to s2
        bool scramblesByNoSwap = compareStrings(s1.substr(0, i), s2.substr(0, i))
                                            && 
                                  // Compare right part of s1 to s2
                                compareStrings(s1.substr(i, n-i), s2.substr(i, n-i));
        // When its scrambled without swap    
        if(scramblesByNoSwap){
            ans = true;
            break;
        }

    }
    return hashMap[key] = ans; // Store the current boolean status of current compared version of s1 and s2
}

// Method to verify s2 is a scrambled version of s1 or not - O(N^4) & O(N^3) 
bool isScramble(string s1, string s2){
    return compareStrings(s1, s2);    
}

// Driver code
int main(){
    string s1 = "great"; string s2 = "rgeat";

    // Method call
    if(isScramble(s1, s2))
        cout<<s2<<" is a scrambled version of "<<s1;
    else
        cout<<s2<<" is not a scrambled version of "<<s1;

    return 0;
}