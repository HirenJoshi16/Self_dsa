// Program to group the anagrams together from an array of strings ~ coded by Hiren
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Method to print given array of strings
void printArrString(vector<string> strs){
    for(auto currStr : strs)
        cout<<"\""<<currStr<<"\"  ";
        
    cout<<'\n';
}

// #1 Method to group the anagrams together - O(N(S*LogS)) & O(N*S)
vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
    int n = strs.size();

    vector<vector<string>> ans; // Stores result
    unordered_map<string, vector<string>> mp;

    for(int i=0; i<n; i++){
        string currString = strs[i]; // Take the current string

        sort(begin(currString), end(currString)); // Sort the current string

        mp[currString].push_back(strs[i]); // Store the sorted version as key and its actual version as value in map
    }

    for(auto it : mp)
        ans.push_back(it.second); // Store the groups

    return ans;
}

// #2 Method Helper: Generates sorted version of given string
string generateSortVersion(string currString){
    int charCount[26] = {0}; // Stores the total count of a character appeared in current string

    for(auto ch : currString){
        int charPos = ch - 'a'; // Take the current character right position
        charCount[charPos]++; // Store its occurrences count to the position
    }

    string newString; // Stores the sorted version
    for(int i = 0; i < 26; i++){
        if(charCount[i] > 0){
            newString += string(charCount[i], i + 'a'); // 
            //  charCount[i] - Takes the number of times the given character has to be created
            //  i + 'a'      - Takes the character to be created
        }
    }
    return newString;
}

// #2 Method to group the anagrams together - O(N*S) & O(N*S)
vector<vector<string>> groupAnagrams_2(vector<string>& strs) {
    int n = strs.size();

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for(auto currString : strs){
        string newString = generateSortVersion(currString); // Take the current string and generate its sorted version

        mp[newString].push_back(currString); // Store the sorted version as key and its actual version as value in map 
    }

    for(auto it : mp)
        ans.push_back(move(it.second)); // Store the anagrams to ans vector by moving the content from map
        // std::move() allows us to transfer the ownership of the contents of a vector to another vector, which can be more efficient than creating a copy of the vector or This is more efficient because it avoids creating unnecessary copies of the vector, which can be expensive in terms of both memory and time.
        
    return ans;
}

// Method to print anagrams result
void printAnagrams(vector<vector<string>> ans){
    cout<<"\nAnagrams : \n";
    for(auto group : ans){
        for(auto currStr : group){
            cout<<"\""<<currStr<<"\"  ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

// Driver code
int main(){
    vector<string> strs{"eat","tea","tan","ate","nat","bat"}; 
    printArrString(strs);

    // Method call
    vector<vector<string>> ans = groupAnagrams_2(strs);
    printAnagrams(ans);

    return 0;
}