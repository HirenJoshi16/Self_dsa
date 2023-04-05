#include <bits/stdc++.h>
using namespace std;

// Evaluates postfix expression
int evaluateExp(string exp){
    stack<int> sp;
         
    // Iterate the expression
    for(int i=0; i<exp.length(); i++){

        // Check if its oprand ~ push it to stack
        if(exp[i] >= '0' && exp[i] <= '9'){
            // (exp[i] -'0') ~ ascii difference of '0' and exp[i] gives exp[i] value in integer 
            sp.push(exp[i] -'0');
        }
        // if its operator ~ pop two values from the stack 
        else{
            int op2 = sp.top();
            sp.pop();
            int op1 = sp.top();
            sp.pop();
                
            switch(exp[i]){
                case '+':
                sp.push(op1+op2);
                break;

                case '-':
                sp.push(op1-op2);
                break;

                case '*':
                sp.push(op1*op2);
                break;

                case '/':
                sp.push(op1/op2);
                break;

                case '^':
                sp.push(pow(op1,op2));
            }
        }
    }
    return sp.top();
}

// Driver code
int main(){
    string exp = "231*+9-"; 
    cout<<evaluateExp(exp);
    return 0;
}