// Program to verify given string is a valid parenthesis string or not ~ coded by Hiren
#include <iostream>
#include <cstring>
#include <stack>
using namespace std; 

// #1 Method to verify given string is a valid parenthesis string or not - O(N) & O(N)
bool isValid(string s){
    stack<char> st;
    
    // Iterate string till end
    for(char ch : s){
        if(st.empty() || ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
            continue;
        }
        else if(ch == ')' && st.top() == '(' || ch == ']' && st.top() == '[' || ch == '}' && st.top() == '{') {
            st.pop();
        }
        else{
            return false;
        }
    }
    return st.empty(); // At last if stack is empty hence true else false
}

// #2 Method to verify given string is a valid parenthesis string or not - O(N) & O(N)
bool isValid(string s){
    stack<char> st;

    // Iterate and insert current bracket's corrosponding bracket
    for(auto ch : s){
        if(ch == '(') 
            st.push(')');

        else if(ch == '[')
            st.push(']');

        else if(ch == '{')
            st.push('}');

        else if(st.empty() || st.top() != ch) // st.empty() - Required when given string is like -> "]" 
            return false;
            
        else
            st.pop(); // When current bracket presents at the top of stack
    }  
    return st.empty();
}

// Driver code
int main(){
    string str = "{()}(";
    // Method call
    if(isValid(str))
        cout<<"Parenthesis string is valid";
    else
        cout<<"Parenthesis string is not valid";

    return 0;
}