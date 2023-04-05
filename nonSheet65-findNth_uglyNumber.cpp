// Program to find Nth ugly number ~ coded by vHiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #1 Method Helper to verify given n is ugly or not
bool isUgly(int n){
    bool isUgly = true;

    while(n > 1){
        // If its divisible by 2 
        if(n%2 == 0)
            n /= 2; // Store the quotient
            
        // If its divisible by 3
        else if(n%3 == 0)
            n /= 3;

        // If its divisible by 5 
        else if(n%5 == 0)
            n /= 5;

        // If its not divisible from 2, 3, 5
        else{
            isUgly = false;
            break;
        }
    }
    return isUgly;
}

// #1 Method to find Nth ugly number - O(N*LogN) & O(1)
int nthUglyNumber_1(int n){
    int currNumber = 1;
    int count = 1;

    while(count < n){
        currNumber++;

        // If current is an ugly number
        if(isUgly(currNumber))
            count++;
    }
    return currNumber;
}

// #2 Method to find Nth ugly number - O(N) & O(N)
int nthUglyNumber_2(int n){
    vector<int> uglyNumbers(n+1); // N+1 to avoid out of bound problems or access within unallocated region
    uglyNumbers[1] = 1; // First ugly number is always 1

    int i2, i3, i5; // Tracks ugly number possibilites for current ugly number
    i2 = i3 = i5 = 1; // Initially at first ugly number

    for(int i=2; i<=n; i++){
        // Generate ugly number possibilities of current ugly number
        int i2_UglyNum = uglyNumbers[i2]*2;
        int i3_UglyNum = uglyNumbers[i3]*3;
        int i5_UglyNum = uglyNumbers[i5]*5;

        // Store the smallest ugly number because its the next ugly number in sequence
        int minUglyNumber = min({i2_UglyNum, i3_UglyNum, i5_UglyNum});
        uglyNumbers[i] = minUglyNumber;

        // Move the pointer whose minimum presents to track possibilities for next ugly number correctly
        if(minUglyNumber == i2_UglyNum) i2++;
        if(minUglyNumber == i3_UglyNum) i3++;
        if(minUglyNumber == i5_UglyNum) i5++;
    }
    
    return uglyNumbers[n];
}
// Note: Multiplication of two ugly number results a ugly number 
// i - Represents sequence number for ith ugly number | A[i] - Represents ith ugly number
// Note: Ugly number possibilities refers to the possibilities limited to multiplication with 2 3 5

// Driver code
int main(){
    int n = 10; cout<<"n : "<<n<<endl; 

    // Method call
    int nthUgly = nthUglyNumber_1(n);
    cout<<"ugly number "<<n<<" is : "<<nthUgly;

    return 0;
}
// Link : https://leetcode.com/problems/ugly-number-ii/