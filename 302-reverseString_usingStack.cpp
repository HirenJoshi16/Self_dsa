// Program to reverse string using stack
// Expected Time Complexity: O(1) for all the four methods.
// Expected Auxiliary Space: O(1) for all the four methods.
#include <bits/stdc++.h>
using namespace std; 

// Function that Reverses string using stack ~ O(n) & O(n) as we are using additional stack
string reverseString1(string str){
    stack<char> sp;

    // Iterate the string
    for(int i=0; i<str.length(); i++){
        sp.push(str[i]);
    }
        str = '\0'; // Initialize string to empty
        // Concate string characters into one while stack not becomes empty
        while(!sp.empty()){
            str += sp.top();
            sp.pop();
        }
    return str;
}

// Driver code
int main(){
    string str = "VHIREN";
    cout<<str<<endl;
    // Revrses string in O(n) & O(n)
    // cout<<reverseString(str);

    // O(1) & O(1) for all the four methods
    stack<char> sp;
    // Push elements to stack
    sp.push('V');
    sp.push('H');
    sp.push('I');
    sp.push('R');
    sp.push('E');
    sp.push('N');

    while(!sp.empty()){
        cout<<sp.top();
        sp.pop();
    }
    return 0;
}