// Program to find maximum number can get by changing at most one digit ~ coded by Hiren
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// #1 Method to find maximum number can get by changing at most one digit - O(N) & O(N) 
int maximum69Number_1(int num){
    string str = to_string(num);

    for(int i=0; i<str.size(); i++){
        if(str[i] == '6'){
            str[i] = '9';
            break;
        }
    }
    return stoi(str);
}

// #2 Method to find maximum number can get by changing at most one digit - Time : O(LogN) | Space : O(LogN) -> O(1) Space
int maximum69Number_2(int num){
    int placeVal = 0;
    int placeValOfSix = -1;
    int temp = num;

    while(temp){
        int rem = temp%10;
        if(rem == 6)
            placeValOfSix = placeVal;

        temp /= 10;
        placeVal++;
    }
    return (placeValOfSix == -1 ? num : num + 3*pow(10, placeValOfSix));
}

// Driver code
int main(){
    int num = 9669; cout<<num<<'\n';

    // Method call
    int maxNum = maximum69Number_1(num);
    cout<<"The maximum number number is : "<<maxNum;
    
    return 0;
}
// Link: https://leetcode.com/problems/maximum-69-number/description/