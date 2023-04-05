#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node
{
    int data;
    struct node *next;
};

// case 1 ~ deletion at the beginning
struct node *deletionHead(struct node *head)
{
    struct node *q = head->next;
    struct node *t = head;

    while (q->next != head)
    {
        q = q->next;
    }
    q->next = t->next;
    head = head->next;
    free(t);

    return head;
}

// case 2 ~ deletion at the end
struct node *deletionEnd(struct node *head)
{
    struct node *t = head;
    struct node *q = head->next;
    while (t->next->next != head)
    {
        t = t->next;
        q = q->next;
    }
    t->next = q->next;
    free(q);
    return head;
}

// case 3 ~ deletion at a given position
struct node *deletionAtPos(struct node *head, int pos)
{
    int i = 1;
    struct node *q = head;
    struct node *t = head->next;
    if (pos == 1)
    {
        struct node *r = deletionHead(head);
        return r;
    }
    else
    {

        while (i != pos - 1)
        {
            t = t->next;
            q = q->next;
            i++;
        }
        q->next = t->next;
        free(t);
    }
    return head;
}

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

// Driver code
int main()
{
    // Creating nodes and allocating their memory dynamically
    struct node *head = new node;
    struct node *second = new node;
    struct node *third = new node;
    struct node *fourth = new node;

    // Connecting the nodes & initializing their data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    traversel(head);
    // cout << endl;
    // head = deletionHead(head);
    // traversel(head);

    // cout << endl;
    // head = deletionEnd(head);
    // traversel(head);

    cout << endl;
    head = deletionAtPos(head, 3);
    traversel(head);
    return 0;
}