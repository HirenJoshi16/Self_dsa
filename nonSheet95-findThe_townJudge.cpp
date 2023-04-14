// Program to find the judge of the town ~ coded by Hiren
#include<iostream>
#include<vector>
using namespace std;

// Method to print vector
void printVector(vector<vector<int>> trust){
    for(auto pair : trust){
        for(auto currPairVal : pair)
            cout<<currPairVal<<" ";
        cout<<'\n';
    }       
    cout<<'\n'; 
}

// #1 Method to find the judge of the town - O(T+N) & O(N)
int findJudge_1(int n, vector<vector<int>>& trust) {
    vector<int> inDegree(n+1); // Tracks count of trust of people made for the guy 
    vector<int> outDegree(n+1); // Tracks count of trust of the guy on someone

    for(vector<int> vec : trust){ // Take each pair by one by one
        inDegree[vec[1]]++; // Increment count when its trustable by someone
        outDegree[vec[0]]++; // Decrement count when its the one who trusts someone because its not the judge

    }

    for(int i=1; i<=n; i++){
        if(inDegree[i] == n-1 && outDegree[i] == 0) // Check is there anyone who have trust of everyone except himself 
            return i; // Than the one is the judge
    }        
    return -1;
}

// #2 Method to find the judge of the town - O(T+N) & O(N)
int findJudge_2(int n, vector<vector<int>>& trust) {
    vector<int> count(n+1); // Tracks count of trust of people for each 

    for(vector<int> vec : trust){ // Take each pair one by one
        count[vec[1]]++; // Increment count when its trustable by someone
        count[vec[0]]--; // Decrement count when its the one who trusts someone because its not the judge
    }

    for(int i=1; i<=n; i++){
        if(count[i] == n-1) // Check is there anyone who have trust of everyone 
            return i; // Than the one is the judge
    }        
    return -1;
}
    
// Driver code
int main(){
    vector<vector<int>> trust{{1,3},
                              {2,3}};
    printVector(trust);
    int n = 3;

    // Method call
    int theJudge = findJudge_2(n, trust);
    cout<<"The judge among "<<n<<" people is "<<theJudge;

    return 0;
}