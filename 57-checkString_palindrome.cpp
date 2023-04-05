//Implemented by Hiren
#include <iostream>
using namespace std;

//Function that checks string is palindrome or not
int isPalindrome(string *A, int n){
    int j=0;

    for(int i=n-1; i>n/2; i--){
        if(A[j] != A[i]){
            return 0;
        }
        j++;
    }
    return 1;
}

//Shows the elements
void printArray(string *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    string A[] = {"H", "I", "R", "I", "H"};
    int n = 5;  
    printArray(A, n);
    cout<<endl;  

    if(isPalindrome(A, n)){
        cout<<"given string is palindrome";
    }
    else{
        cout<<"given string is not palindrome";
    }
    return 0;
}