// Program to find the index of first occurrence of needle in haystack ~ coded by vHiren
#include <iostream>
#include <string>
using namespace std;

// #1 Method to find index of first occurrence of needle in haystack - O(M*N) & O(1)
int firstOccurrence(string haystack, string needle){
    int sizeH = haystack.length();
    int sizeN = needle.length();

        for(int i = 0; i <= sizeH-sizeN; i++){
            if(needle == haystack.substr(i, needle.length()))
                return i;
        }

    return -1;
}

// #2 Method to find index of first occurrence of needle in haystack - O(N*M) & O(1)
int firstOccurrence_2(string haystack, string needle){
    int sizeH = haystack.length();
    int sizeN = needle.length();

        for(int i = 0; i < sizeH; i++){
            int currCharInH = i;
            int currCharInN = 0;
            int charTillNowInN = 0;

            while(currCharInN < sizeN && haystack[currCharInH] == needle[currCharInN]){
                currCharInH++;
                currCharInN++;
                charTillNowInN++;
            }
            if(charTillNowInN == sizeN) return i;
        }

    return -1;
}

// Driver code
int main(){
    string haystack = "angelomichael";
    string needle = "michael";

    // Print the strings
    cout<<"haystack : "<<haystack; 
    cout<<"\nneedle : "<<needle;

    // Method call
    int occurrenceIndex = firstOccurrence(haystack, needle);
    cout<<"\n\nThe first occurrence of needle in haystack is : "<<occurrenceIndex;

    return 0;
}