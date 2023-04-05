// Program to find each subarray with zero sum in array ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays array elements
void printArray(long long *A, long n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// #1 - Finds count of subarrays with zero sum ~ O(n) & O(n)
long long countSubArrays_withZeroSum(long long *A, long n){
    // Edge case
    if(n <= 0) return 0;
    
    long long sum = 0;
    long count = 0;
    unordered_map<long long, long> uMap; // Create a map
    uMap[0] = 1; // In case subarray found from index 0 

        // Iterate array till end
        for(int i=0; i<n; i++){
            sum += A[i];
            // Increment count if sum present in the map
            if(uMap.find(sum) != uMap.end()){
                count += uMap[sum];
            }
            uMap[sum]++; // Insert current sum with its frequency in map 
        }
    return count;
}

// #2 - Prints subarrays with zero sum ~ O(n) & O(n)
bool printSubArrays_withZeroSum(long long *A, long n){
    // Edge case
    if(n <= 0) return false;

    unordered_multimap<long long, long> uMap; // Create a multimap
    long long sum = 0;
    long long count = 0;
    uMap.insert(pair<int, int>(0, -1)); // In case subarray found from index 0 

        // Iterate array till end
        for(long i=0; i<n; i++){
            sum += A[i];

            // If sum present in map
            if(uMap.find(sum) != uMap.end()){
                auto it = uMap.find(sum);
                // Track the indeces with subarray in map
                while(it != uMap.end() && it->first == sum){
                    cout<<"Subarray From Index "<<it->second + 1<<" To "<<i<<endl;
                    it++;
                }
            }
            // Insert sum till now & current index as pair in map 
            uMap.insert(pair<long long, long>(sum, i));
        }        
    return true;
}

// Driver code
int main(){
    long long A[] = {7, 1, 2, -3, 5, -1, 1, 0, 8};
    long n = 9;
    printArray(A, n);

    // Function call
    if(printSubArrays_withZeroSum(A, n)){
        exit(1);
    }
    else{
        cout<<"No subarray exists!"<<endl;
    }
    return 0;
}