// coded by vHiren ~ T.C - O(n) & O(n)
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main(){
    string str = "geeksforgeeks";
    unordered_set<char> uset;

    // Find that value into set if its not there insert it to uset
        for(auto i : str){
            if(uset.find(i) != uset.end()){
                cout<<"first repeated word to string is : "<<i;
                exit(0);
            }
            else{
                uset.insert(i);
            }
        }
    return 0;
}