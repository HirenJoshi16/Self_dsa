#include <bits/stdc++.h>
using namespace std;

// Driver code
int main(){
    vector<int> input({1, 2, 2, 1, 3, 1, 8, 4});
    multiset<int> mSet(input.begin(), input.end());

    cout<<"[ ";
    for (const int &i : mSet){
        cout<<i<<" ";
    }
    cout<<"]";
    
    return 0;
}
