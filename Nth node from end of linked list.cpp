//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


/*
1. If we reach the end of the linked list(curr) before n reaches zero, it means that 
    the gap of n nodes could not be covered. In such a case, the answer is set to -1, 
    indicating that the nth node from the end does not exist.

2. If n reaches zero, it implies that we have successfully reached the desired gap of n nodes. 
    Subsequently, we iterate both the current node (curr) and the saved node (save). 
    The rationale behind this is as follows: If the curr node eventually reaches null, 
    it signifies that the save node is precisely n steps behind the current node. 
    This aligns with our goal of finding the nth node from the end of the linked list.
*/

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    Node *curr = head;
    Node *save = head;

    while (curr)
    {
        if (n)
        {
            curr = curr->next;
            n--;
        }
        else
        {
            save = save->next;
            curr = curr->next;
        }
    }
    if (n)
    {
        return -1;
    }
    return save->data;
}

/* Another approach

int getNthFromLast(Node *head, int n)
{
    int length = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        length++;
    }

    int steps = length - n;
    if (steps < 0)
    {
        return -1;
    }
    temp = head;
    for (int i = 0; i < steps; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

*/