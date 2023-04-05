// Program to generate list of all self dividing numbers in given range ~ coded by vHiren
// A self dividing number is a number that is divisible by every digit it contains. A self dividing number is not allowed to contain the digit zero
#include <iostream>
#include <vector>
using namespace std;

// Method to generate all self dividing numbers in given range - O(n) & O(1)
vector<int> generate_selfDividingNumbers(int left, int right){
    vector<int> ans;

    for(; left<=right; left++){
        int tmp = left;
        bool trueDivisor = false;

        // Take the current value and check for it
        while(tmp != 0){
            int remVal = tmp%10;

            if(remVal != 0 && left%remVal == 0)
                trueDivisor = true;
            else{
                trueDivisor = false;
                break;
            }    

            tmp /= 10;
        }
        if(trueDivisor) 
            ans.push_back(left);
    }

    return ans;
}

// Driver code
int main(){
    vector<int> nums = generate_selfDividingNumbers(47, 85);
    // Printing values
    for(auto val : nums)    
        cout<<val<<" ";

    return 0;
}