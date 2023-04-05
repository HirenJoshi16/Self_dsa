// Program to find best time to sell stock ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Displays stock prices
void printStocks(vector<int> stock){
    for(auto price : stock){
        cout<<price<<" ";
    }
    cout<<endl;
}

// #1 - Function to find maximum profit of stock ~ O(n) & O(1)
int findMaxProfit1(vector<int>& stock){
    // Edge case
    if(stock.size() <= 0) return 0;

    int n = stock.size();
    int maxStock = stock[n-1];
    int maxProfit = 0;

    // Iterate vector till first element
    for(int price = n-2; price >= 0; price--){
        maxStock = max(stock[price], maxStock);
        maxProfit = max(maxProfit, maxStock - stock[price]);
    }
    return maxProfit;
}   

// #2 - Function to find maximum profit of stock ~ O(n) & O(1)
int findMaxProfit2(vector<int>& stock){
    // Edge case
    if(stock.size() <= 0) return 0;

    int buy = stock[0];
    int maxProfit = 0;

    // Iterate vector till end
    for(int price = 1; price < stock.size(); price++){
        // Find stock with lower price 
        if(buy > stock[price])
            buy = stock[price];
            
        // Take stock with higher profit
        else if(stock[price] - buy > maxProfit)
            maxProfit = stock[price] - buy;
    }
    return maxProfit;
}   

// Driver code
int main(){
    vector<int> stock{7, 1, 3, 5, 4};
    printStocks(stock);

    // Function call
    int maxProfit = findMaxProfit2(stock);
    if(maxProfit){
        cout<<"Profit : "<<maxProfit;
    }   
    else{
        cout<<"Market closed!";
    }
    return 0;
}