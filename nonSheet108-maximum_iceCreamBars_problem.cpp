// Program to find maximum number of ice cream bars the boy can buy with coins ~ coded by Hiren
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method to print ice cream costs
void printCosts(vector<int> costs){
    for(auto currCost : costs)
        cout<<currCost<<" ";

    cout<<'\n';
}

// Method to find maximum number of ice cream bars the boy can buy with coins - O(NLogN) & O(1)
int maxIceCream(vector<int>& costs, int coins){
    sort(begin(costs), end(costs));
    int maxCreamBars = 0;

    for(auto currCost : costs){
        if(coins < currCost)
            // When its not possible to buy the current one
            return maxCreamBars;
        else
            // When its possible to buy the current one
            maxCreamBars++;
            coins -= currCost;
    }
    return maxCreamBars;
}

// Driver code
int main(){
    vector<int> costs{1, 6, 3, 1, 2, 5}; int coins = 20;
    printCosts(costs);

    // Method call
    int maxCreamBars = maxIceCream(costs, coins);
    cout<<"The maximum number of ice cream the boy can buy is : "<<maxCreamBars;
    
    return 0;
}
// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/