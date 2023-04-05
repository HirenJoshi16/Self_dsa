// Program to find number of zero filled subarrays in an array ~ coded by vHiren
#include<iostream>
#include<vector>

// Method to print vector
void printVector(std::vector<int> arr){
    for(auto val : arr)
        std::cout<<val<<" ";

    std::cout<<'\n';    
}

// #1 Method to find number of zero filled subarrays in an array - O(N) & O(1)
long long zeroFilledSubarray_1(std::vector<int>& arr){
    int n = arr.size();

    int i = 0;
    long long zeroFilledCurrent = 0;
    long long zeroFilledTillNow = 0;

        while(i < n){

            if(arr[i] == 0){
                // Take contiguous count of zeros
                while(i < n && arr[i] == 0){
                    zeroFilledCurrent++;
                    i++;
                }

                // N(N+1)/2 --> Produces number of subarrays can made from current array
                zeroFilledTillNow += (zeroFilledCurrent)*(zeroFilledCurrent+1)/2; 
            }
            else{
                zeroFilledCurrent = 0; // To check for upcoming subarray of zeros
                i++;
            }

        }
    
    return zeroFilledTillNow;
}

// #2 Method to find number of zero filled subarrays in an array - O(N) & O(1)
long long zeroFilledSubarray_2(std::vector<int>& arr){
    long long n = arr.size();

    long long zeroFilledTillNow = 0; // Tracks total zero filled subarray seen till now
    long long zeroFilledCurrent = 0; // Tracks total zero filled subarray can be seen from current zero to previously ending zero

        for(auto val : arr){
        
            // When current value is zero
            if(val == 0)
                zeroFilledCurrent++, 
                zeroFilledTillNow += zeroFilledCurrent; // Add to keep track of total subarray seen till now
    
            // When current value is not zero
            else
                zeroFilledCurrent = 0;
    
        }

    return zeroFilledTillNow;
}

// Driver code
int main(){
    std::vector<int> arr{0, 0, 0, 2, 0, 0};
    printVector(arr);

    // Method call
    int zeroFilledStreak = zeroFilledSubarray_1(arr);
    std::cout<<"Total zero filled subarray is : "<<zeroFilledStreak;

    return 0;
}