// Program to find maximum length of a concatenated string with unique characters ~ coded by Hiren
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

// Method to print array
void printArray(vector<string> arr){
    for(auto str : arr)
        cout<<"\""<<str<<"\""<<" ";

    cout<<'\n';
}

// Method Helper: Verifies given strings consist of any duplicate character or not 
bool hasDuplicate(string &arrStr, string &temp){
    int charFreq[26] = {0};

    for(auto &ch : arrStr){
        if(charFreq[ch-'a'] > 0) // Case when the given string itself contains duplicate like - "aa", "bb"
            return true;
        charFreq[ch-'a']++;
    }

    for(auto &ch : temp){
        if(charFreq[ch-'a'] > 0)
            return true;
    }

    return false;
}

unordered_map<string, int> mp; // Used for memoization

// Method Helper: Finds maximum length
int maxLength(vector<string>& arr, int n, int index, string temp){
    // Edge case
    if(index >= n)
        return temp.length();

    if(mp.count(temp)) // If length for current temp string is already computed
        return mp[temp]; // Simply return the length

    int includeLen = 0; // Tracks the maximum length by include 
    int excludeLen = 0; // Tracks the maximum length by exclude
    
    // If duplicate exist than we can't include the current string in temp hence move further to do the same for the next string
    if(hasDuplicate(arr[index], temp)){
        excludeLen = maxLength(arr, n, index+1, temp);
    }
    // Else we have to include the current string in temp than move further to do the same for the next string
    else{
        excludeLen = maxLength(arr, n, index+1, temp);
        includeLen = maxLength(arr, n, index+1, temp+arr[index]); 
    }

    return mp[temp] = max(includeLen, excludeLen); // Store the maximum length and return it
}
// Note: When there is no duplicate, We have two choices :-
// 1. Exclude the string
// 1. Include the string

// Note: When there is duplicate, We have only one choice :-
// 1. Exclude the string - Means dont take the current one, Just move further

// Method to find maximum length of concatenated string - O(2^N * M) & (2^N + N + M)
int maxLength(vector<string>& arr){
    int n = arr.size();
    string temp = ""; // Tracks the resultant string with maximum length

    return maxLength(arr, n, 0, temp);
}

// Driver code
int main(){
    vector<string> arr{"un","iq","ue"}; 
    printArray(arr);   
    
    // Method call

    return 0;
}

/* 

Time complexity:
The hasDuplicate function runs in O(m), where m is the length of the input string.
The maxLength function is a recursive function that is called for each string in the input vector, and it makes two recursive calls for each string. Hence, the time complexity of the maxLength function is O(2^n), where n is the length of the input vector. However, the memoization technique is used to store the results of subproblems, so the actual time complexity will be reduced by the number of overlapping subproblems. Therefore, the time complexity of the entire code is O(2^n * m).

Space complexity:
The hasDuplicate function uses an array of size 26 to store the frequency of each character in the input string, which is a constant amount of space. The maxLength function uses the mp map to store the results of subproblems, which can have at most 2^n entries. The maximum depth of the recursive call stack is n. Additionally, the temp string can have at most n characters. Therefore, the space complexity of the entire code is O(2^n + n + m).

In summary, the time complexity of the given code is O(2^n * m), and the space complexity is O(2^n + n + m).

*/