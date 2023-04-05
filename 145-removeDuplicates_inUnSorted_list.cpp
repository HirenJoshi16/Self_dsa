// Remove duplicates in a Unsorted linked list ~ T.C - O(n), S.C - O(n)
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node
{
    int data;
    struct node *next;
};

// Traverses each node
void traversel(struct node *head)
{
    struct node *tmp = head;
    do
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != head);
}

// Removes duplicates to list
struct node *removeDuplicate(struct node *head)
{
    // creating an unordered set
    unordered_set<int> seen; // Here seen is the name of unordered set of integer values, unordered set defines set in which non repeating values can be inserted, if we try to insert a same value, the value will be overplaced to that same value in the set - 5 ko insert krna chaha but 5 set me pehle se tha so 5 ka vps 5 hi ho jaaega

    struct node *curr = head;
    struct node *prev = NULL;

    while (curr != NULL)
    {
        // If current value is in the set 
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    return head;
}

// Driver code
int main()
{
    // Creating nodes and allocating their memory dynamically
    struct node *head = new node;
    struct node *second = new node;
    struct node *third = new node;
    struct node *fourth = new node;
    struct node *fifth = new node;

    // Connecting the nodes & initializing their data
    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = fifth;

    fifth->data = 2;
    fifth->next = NULL;

    // traversel(head);
    cout << endl;
    head = removeDuplicate(head);
    traversel(head);
    return 0;
}