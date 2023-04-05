// Program to find maximum profit can made from all transactions ~ coded by vHiren
// All the Elements are share price of a single stock 
// Can do multiple transactions, You can buy it then immediately sell it on the same day
// Condition follow up - 1. Once buy do not buy again 2. Must sell before buy 3. Dont sell the same share again
#include <bits/stdc++.h>
using namespace std;

// Displays share prices
void printSharePrice(vector<int> stockShare){
    for(auto price : stockShare){
        cout<<price<<" ";
    }
    cout<<endl;
}

// Method to find maximum profit of stock - O(n) & O(1)
int findMaxProfit(vector<int>& stockShare){
    int n = stockShare.size();
    // Edge case
    if(n<=0) return 0;

    long long maxProfit = 0;
        
        for(int price=0; price<n-1; price++){
            // As we want max profit and we know we can have it buy selling it at the profitable price hence for this we are adding the difference of adjacent pairs or we can say if its profitable to sell the next day we will add up the profit
            if(stockShare[price] < stockShare[price+1])
                maxProfit += stockShare[price+1] - stockShare[price];
        }
        
    return maxProfit;
}    

// Driver code
int main(){
    vector<int> stockShare{1, 0, 0, 8, 5};
    printSharePrice(stockShare);

    // Method call
    int maxProfit = findMaxProfit(stockShare);
    if(maxProfit){
        cout<<"Profit : "<<maxProfit;
    }   
    else{
        cout<<"Market closed!";
    }
    return 0;
}