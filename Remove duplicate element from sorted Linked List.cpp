//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *root);
int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to remove duplicates from sorted linked list.

/*
Remove duplicate element from sorted Linked List

Example 1)
Input:
1
4
2 2 4 5

Output:
2 4 5

Example 2)
Input:
1
5
2 2 2 2 2

Output:
2


*/
Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *curr = head;
    Node *temp;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            temp = curr->next;
            curr->next = curr->next->next; // Skip the duplicate element
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}