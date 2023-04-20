// Program to design browser history - coded by Hiren
#include <iostream>
#include <stack>
using namespace std;

// Class to design browser history - O(K) & O(N) --> N is the total number of visited URLs. This is because at any time, The class stores the current URL and two stacks, backHistory and forwardHistory, each of which may contain up to N URLs in the worst case. Therefore, the overall space complexity of the class is O(N).
class BrowserHistory {
public:
    stack<string> backHistory; // Tracks past reaches 
    stack<string> forwardHistory; // Tracks future reaches
    string curr; // Tracks current reach

    // O(1)
    BrowserHistory(string homepage) {
        curr = homepage; // Current homepage
    }
    
    // O(1)
    void visit(string url) {
        backHistory.push(curr); // Store this page
        curr = url; // Visit the url

        forwardHistory = stack<string> (); // Clears the stack
    }
    
    // O(K) Where K is the number of steps to move in backHistory
    string back(int steps) {

        while(steps > 0 && !backHistory.empty()) {
            forwardHistory.push(curr);

            curr = backHistory.top();
            backHistory.pop();
            steps--;
        }
        return curr;
    }
    
    // O(K) Where K is the number of steps to move in forwardHistory
    string forward(int steps) {

        while(steps > 0 && !forwardHistory.empty()) {
            backHistory.push(curr);
            
            curr = forwardHistory.top();
            forwardHistory.pop();
            steps--;
        }
        return curr;
    }
};

// Driver code
int main() {
    // Initialization
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    string url1 = obj->back(1);
    string url2 = obj->back(1);
    string url3 = obj->forward(2);

    cout<<url1<<endl<<url2<<endl<<url3;
    
    return 0;
}
// Link: https://leetcode.com/problems/design-browser-history/description/

// Total 3 Ways to solve this problem :-
// 1. Using 2-Stack
// 2. Using Doubly Linked List
// 3. Using Vector