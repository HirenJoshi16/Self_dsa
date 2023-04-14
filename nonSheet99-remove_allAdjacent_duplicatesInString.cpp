// Program to remove all adjacent duplicates in string ~ coded by Hiren
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

// #1 Method to remove all adjacent duplicates in string - O(N) & O(N)
string removeDuplicates_2(string s){
    stack<char> st;

    for(auto ch : s){
        if(st.empty() || st.top() != ch)
            st.push(ch);
        else
            st.pop();
    }

    string ans = ""; // To store the result
    while(!st.empty()){
        ans.push_back(st.top()); // Store the character to ans one by one
        st.pop();
    }
    reverse(begin(ans), end(ans)); // Reverse the ans string

    return ans;
}

// #2 Method to remove all adjacent duplicates in string - O(N) & O(N)
string removeDuplicates_1(string s){
    string ans = "";

    for(auto ch : s){
        if(ans.empty() || ans.back() != ch)
            ans.push_back(ch);
        else
            ans.pop_back();
    }
    return ans;
}

// Driver code
int main(){
    string s = "abbaca"; 
    cout<<s<<'\n';    
    
    // Method call
    string ans = removeDuplicates_2(s);
    cout<<ans;    

    return 0;
}