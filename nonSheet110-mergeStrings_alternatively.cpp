// Program to merge given strings alternately ~ coded by Hiren
#include <iostream>
#include <cstring>
using namespace std;

// Method to merge strings alternately - O(max(n, m)) & O(max(n, m))
string mergeAlternately(string word1, string word2){
    int n = word1.length();
    int m = word2.length();
    string ans = "";

    for(int i = 0; i < max(n, m); i++){
        if(i < word1.length())
            ans.push_back(word1[i]); 

        if(i < word2.length())
            ans.push_back(word2[i]);   
    }

    return ans;
}

// Driver code
int main(){
    string s1 = "abc";
    string s2 = "pqrst";
    cout<<s1<<"   "<<s2<<'\n';
    
    // Method call
    string ans = mergeAlternately(s1, s2);
    cout<<ans;

    return 0;
}
