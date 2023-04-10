// Program to verify given string sentence is a pangram or not ~ coded by vHiren
#include<iostream>
#include<vector>
using namespace std;

// Method to verify given sentence is a pangram or not - O(S) & O(1)
bool isPangram(string sentence) {
    vector<int> arr(26, 0); // 26 sized array of value zero
    int charCount = 0; 
    
    for(auto ch : sentence){
        int charPos = ch - 'a';
        if(arr[charPos] == 0)
            arr[charPos]++,
            charCount++;
    }
    return (charCount == 26 ? true : false);    
}

// Driver code
int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    // Method call
    if(isPangram(sentence))
        cout<<sentence<<" is a pangram";
    else
        cout<<sentence<<" is not a pangram";

    return 0;
}