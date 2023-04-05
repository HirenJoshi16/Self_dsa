// Program to verify three consecutive odds present in array or not ~ coded by vHiren
#include <iostream>
#include <vector>
using namespace std;

// Method to print vector
void printVector(vector<int> arr, int i=0){
    if(i == arr.size()){
        cout<<'\n';
        return;
    }
    cout<<arr[i]<<" ";
    printVector(arr, ++i);
}

// Method to verify three consecutive odds present in array or not - O(n) & O(1)
bool threeConsecutiveOdds(vector<int>& arr) {
    // Edge case
    if(arr.size()<=2)
        return false;

        for(int i=0; i<=arr.size()-3; i++){
            // If odds found
            if(arr[i]%2 == 1 && arr[i+1]%2 == 1 && arr[i+2]%2 == 1)
                return true;
        }

    return false;
}

// Driver code
int main(){
    vector<int> arr{1, 2, 5, 6, 3, 5, 7};
    printVector(arr);

    // Method call
    if(threeConsecutiveOdds(arr))
        cout<<"Three consecutive odds present";
    else
        cout<<"Three consecutive odds not present";

    return 0;
}