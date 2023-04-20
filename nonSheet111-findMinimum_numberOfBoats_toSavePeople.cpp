// Program to find minimum number of boats to save people ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to print peoples weight
void printWeight(vector<int> people){
    for(auto weight : people)
        cout<<weight<<" ";

    cout<<'\n';
}

// Method to find minimum number of boats to save people - O(NLogN) & O(1)
int numRescueBoats(vector<int>& people, int limit){
    int n = people.size();

    sort(begin(people), end(people)); // Makes easier to take heavy person and lighter person 
    int i = 0; 
    int j = n-1;
    int minBoats = 0;

    while(i <= j){
        if(people[j] + people[i] <= limit) // Check two peoples at a time as each boat can save only two
        // If its possible to take the lighter person with heavy person than save both
            i++, 
            j--;
        else
        // If its not possible to take the lighter person with heavy person than save the heavy one
            j--;
        minBoats += 1; // Take the boat each time as we are taking both the people or the heavy one necessarily
    }
    return minBoats;
}

// Driver code
int main(){
    vector<int> people{10, 6, 5, 8}; int limit = 3;
    printWeight(people);
    
    // Method call
    int minBoats = numRescueBoats(people, limit);
    cout<<"The minimum boats required to save people is : "<<minBoats; 

    return 0;
}
// Link: https://leetcode.com/problems/boats-to-save-people/description/