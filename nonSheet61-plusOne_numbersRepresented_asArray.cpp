// Program to increment the large integer by one ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Method to plus one to numbers represented as array - O(n) & O(1)
vector<int> plusOne(vector<int>& digits){
    int n = digits.size()-1;

    for(int i=n; i>=0; i--){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.push_back(0); digits[0] = 1;

    return digits;
}

// Driver code
int main(){
    vector<int> digits{9, 9, 9, 9};

    // Method call
    digits = plusOne(digits);
    // Print values
    for(auto val : digits) 
        cout<<val<<" ";

    return 0;
}
