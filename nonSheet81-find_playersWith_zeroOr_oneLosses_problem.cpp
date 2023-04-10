// Program to find list of players with no losses and one losses ~ coded by Hiren
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Method to find list of players with no losses and one losses - O(NLogN) & O(lostMap)
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> lostMap;

    for(int i = 0; i < matches.size(); i++){
        int loser = matches[i][1];
        lostMap[loser]++;
    }

    vector<int> noLost;
    vector<int> onceLost;

    for(int i = 0; i < matches.size(); i++){
        int winner = matches[i][0];
        int loser = matches[i][1];

        if(lostMap.find(winner) == lostMap.end()){
            noLost.push_back(winner);
            lostMap[winner] = 2; // Insert to avoid storing duplicate in the output list
        }
        if(lostMap[loser] == 1){
            onceLost.push_back(loser);
        }
    }
    // Sort the vector lists
    sort(begin(noLost), end(noLost));
    sort(onceLost.begin(), onceLost.end());

    return {noLost, onceLost};   
}

// Driver code
int main(){
    vector<vector<int>> matches{{1,3}, {2,3}, {3,6}, {5,6}, {5,7}, {4,5}, {4,8}, {4,9}, {10,4}, {10,9}};

    // Method call
    vector<vector<int>> winnersList = findWinners(matches);
    // Printing values
    for(int i = 0; i < winnersList.size(); i++){
        for(int j = 0; j < winnersList[i].size(); j++){
            cout << winnersList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/