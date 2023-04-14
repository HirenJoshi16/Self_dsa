// Program to verify can place given N flowers or not ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to print array
void printArray(vector<int> flowerBed){
    for(auto val : flowerBed)
        cout<<val<<" ";

    cout<<'\n';
}

// #1 Method to verify can place given N flowers or not - O(S) & O(S)
bool canPlaceFlowers_1(vector<int>& flowerBed, int n){
    // Requires to handle checks for first index and last index in the original array
    flowerBed.insert(flowerBed.begin(), 0); // Insert 0 at the beginning
    flowerBed.push_back(0); // Insert 0 at the end
    
    int size = flowerBed.size();
    int tillPlaced = 0; // Tracks flowers placed till now

    for(int i=1; i<=size-2; i++){
        if(flowerBed[i] == 0 && flowerBed[i-1] == 0 && flowerBed[i+1] == 0)
            flowerBed[i] = 1,
            tillPlaced++;
    }

    return (tillPlaced >= n ? true : false); 
}

// #2 Method to verify can place given N flowers or not - O(S) & O(1)
bool canPlaceFlowers_2(vector<int>& flowerBed, int n){
    int size = flowerBed.size();
    // Edge case
    if(n == 0) 
        return true;

    for(int i = 0; i < size; i++){
        if(flowerBed[i] == 0){
            bool leftEmpty = (i == 0 || flowerBed[i-1] == 0); // Evaluates to true when its the first index or left side is empty
            bool rightEmpty = (i == size-1 || flowerBed[i+1] == 0); // Evaluates to true when its the last index or right side is empty

            if(leftEmpty && rightEmpty){
                flowerBed[i] = 1; // Put the flower
                n--; 

                if(n == 0)
                    return true;
            }
        }
    }   
     
    return false;
}

// Driver code
int main(){
    vector<int> flowerBed{1, 0, 0, 0, 1};
    printArray(flowerBed); int n = 2;

    // Method call
    if(canPlaceFlowers_2(flowerBed, n))
        cout<<"Can place "<<n<<" flower!";
    else
        cout<<"Can not place "<<n<<" flower!";

    return 0;
}