// Program to check given expression is balanced or not | coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// #1 Checks expression is balanced or not
bool parenthesisMatch(string exp){
    stack<int> sp;

    // Iterate the expression
    for(int i=0; i<exp.length(); i++){
        if(exp[i] == '('){
            sp.push(exp[i]);
        }
        if(exp[i] == ')'){
            if(sp.empty()){
                return false;
            }
            sp.pop();
        }
    }
    // At last check stack is empty or not
    if(sp.empty()){
        return true;
    }
    return false;
}

// Checks values ally or not
bool match(char a, char b){
    if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}'){
        return true;
    }
    return false;
}

// #2 Checks expression is balanced or not
bool MultiparenthesisMatch(string exp){
    stack<int> sp;
    char poppedVal;

    // Iterate the expression
    for(int i=0; i<exp.length(); i++){

        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            sp.push(exp[i]);
        }
        if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            // If stack turn out to be empty
            if(sp.empty()){
                return false;
            }
            poppedVal = sp.top();
            sp.pop();
            if(!match(poppedVal, exp[i])){
                return false;
            }
        }
    }
    // If stack becames empty in end
    if(sp.empty()){
        return true;
    }
    return false;
}

// Driver code
int main(){
    // string exp = "(a+b)*(c+d)";
    // if(parenthesisMatch(exp)){
    //     cout<<"given expression is balanced";
    // }
    // else{
    //     cout<<"given expression is not balanced";
    // }

    string exp = "[(a+b)*(c+d)]";
    if(MultiparenthesisMatch(exp)){
        cout<<"given expression is balanced";
    }
    else{
        cout<<"given expression is not balanced";
    }
    return 0;
}