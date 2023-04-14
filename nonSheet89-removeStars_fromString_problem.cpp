// Program to remove stars from a given string ~ coded by Hiren
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std; 

// #1 Method to remove stars from given string - O(S) & O(S)
string removeStars_1(string s){
    stack<char> st;

    for(auto ch : s){
        if(ch == '*'){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }  

    string ans = ""; // Stores result
    while(!st.empty()){
        ans.push_back(st.top()),
        st.pop();
    }

    reverse(begin(ans), end(ans)); // Reverse the result string
    return ans; 
}

// #2 Method to remove stars from given string - O(S) & O(S)
string removeStars_2(string s){
    string ans = "";

    for(auto ch : s){
        if(ch == '*')
            ans.pop_back();
        else
            ans.push_back(ch);
    }  
    return ans; 
}

// #3 Method to remove stars from given string - O(S) & O(S)
string removeStars_3(string s){
    int n = s.length();
    vector<char> ch(n);
    int j = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            j--;
        }
        else{
            ch[j++] = s[i]; // Stores the element at ch[j] than increments j
        }
    }

    string ans = "";
    for(int i = 0; i <= j-1; i++){
        ans.push_back(ch[i]);
    }
    return ans;
}

// Driver code
int main(){
    string s = "leet**cod*e"; cout<<s;
    // Method call
    string ans = removeStars_2(s);
    cout<<'\n'<<ans;

    return 0;
}
// Link: https://leetcode.com/problems/removing-stars-from-a-string/description/