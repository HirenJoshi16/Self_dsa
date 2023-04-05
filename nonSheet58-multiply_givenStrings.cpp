// Program to multiply given strings ~ coded by vHiren
#include <iostream>
#include <string>
using namespace std;

// #1 Method to multiply given strings - O(s1 + s2) & O(s1 + s2)
string multiplyStrings(string s1, string s2){
    int i=0;
    long long val1, val2;
    val1 = val2 = 0;

        while(i != s1.length()){
            long tmp1 = s1[i] - '0'; // Store the current character in numeric
            val1 = (val1*10) + tmp1; // Build the numeric
            i++;
        } 

        i=0;
        while(i != s2.length()){
            long tmp2 = s2[i] - '0'; // Store the current character in numeric
            val2 = (val2*10) + tmp2; // Build the numeric
            i++;
        }   
        string ans = to_string(val1*val2); // Take the product 

    return ans;
}

// #2 Method to multiply given strings - O(s1*s2) & O(s1+s2)
string multiplyStrings_2(string s1, string s2){
    // Edge case
    if(s1 == "0" || s2 == "0") return "0";

    string ans(s1.size()+s2.size(), '0'); // Initially fill zeros to avoid garbage values

    for(int i = s1.size()-1; i >= 0; i--){
        for(int j = s2.size()-1; j >= 0; j--){
            int res = (ans[i+j+1]-'0') + (s1[i]-'0') * (s2[j]-'0');
            ans[i+j+1] = res%10 + '0'; // Ones place of current result
            ans[i+j] += res/10; // If carry then place it to previous index
        }
    }

    // In case leading is 0 then return the remaining string
    if(ans[0] == '0') return ans.substr(1);

    return ans;
}

// Driver code
int main(){
    string s1 = "22", s2 = "6";
    cout<<s1<<"  "<<s2<<endl;

    // Method call
    cout<<multiplyStrings_2(s1, s2);

    return 0;
}