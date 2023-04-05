#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

// Driver code
int main()
{
    vector<int> input({1, 2, 2, 1, 3, 1, 4});
    set<int> set(input.begin(), input.end());

    for(const int &i : set){
        cout<<i<<" ";
    }
    return 0;
}