// Program to verify given N is a perfect square or not ~ coded by vHiren
#include<iostream>
using namespace std;

// #1 Method to verify given N is a perfect square or not - O(sqrt(N)) & O(1)
bool isPerfectSquare(int num) {
    for(long long i = 1; i*i <= num; i++){
        if(i*i == num)
            return true;
    }   
    return false;     
}

// #2 Method to verify given N is a perfect square or not - O(logN) & O(1)
bool isPerfectSquare_2(int num) {
    int start = 1;
    int end = num;

        while(start <= end){
            int mid = start + ((end - start)/2);
            long long squareVal = (long long) mid*mid; // Typecasting required to avoid integer overflow

            if(squareVal == num)
                return true;

            else if(squareVal > num)
                end = mid-1;
                
            else    
                start = mid+1;
        }

    return false;
}

// Driver code
int main(){
    int n = 16;
    // Method call
    if(isPerfectSquare_2(n))
        cout<<n<<" is a perfect square";
    else
        cout<<n<<" is not a perfect square";

    return 0;
}