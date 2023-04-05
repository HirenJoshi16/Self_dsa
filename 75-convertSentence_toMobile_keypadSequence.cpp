// Program to convert sentence to its equivalent keypad sequence ~ coded by vHiren
#include <iostream>
#include <set>
using namespace std;

// Function to display keypad sequence of given sentence ~ O(n) & O(n)
void printNumericSequence(string* seq, string inputSentence){
    // Edge case
    if(!seq) return;

    int size = inputSentence.size();

    // Iterate given string
    for(int i=0; i<size; i++){
        // Check for blank space
        if(inputSentence[i] == ' '){
            cout<<"0";
        }
        // Print numeric sequence from index value 
        else{
            int index = inputSentence[i] - 'A'; // Take index value by current character - 65
            cout<<seq[index];
        }
    }    
}

// Driver code
int main(){
    // Store keypad sequence
    string seq[] = {"2", "22", "222", "3", "33", "333", "4", 
                    "44", "444", "5", "55", "555", "6", "66", 
                    "666", "7", "77", "777", "7777", "8", 
                    "88", "888", "9", "99", "999", "9999"};
    string inputSentence = "HIREN";

    // Function call
    printNumericSequence(seq, inputSentence);
    return 0;
}