// Program to reverse vowels in given string ~ coded by Hiren
#include <iostream>
#include <cstring>
using namespace std; 

// Method hepler: Checks given character is a vowel or not
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;

    return false;
}

// Method to reverse vowels in given string - O(S) & O(1)
string reverseVowels(string& s) {
    int i = 0;
    int j = s.size()-1;

    while(i < j){
        // Move i when current character is not a vowel
        if(!isVowel(s[i]))   
            i++;

        // Move j when current character is not a vowel
        else if(!isVowel(s[j]))
            j--;
            
        // Swap the vowels, When both i and j are vowel
        else   
            swap(s[i], s[j]),
            i++,
            j--;
    }
    return s;
}

// Driver code
int main(){
    string s = "LeetCode"; cout<<s;
    // Method call
    reverseVowels(s);
    cout<<endl<<s;

    return 0;
}
// Note: Problem can also solved using stack in O(S) & O(S)