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

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node *deleteNode(struct Node *head, int);

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }

        int kk;
        cin >> kk;
        head = deleteNode(head, kk);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/

/*
Delete a Node in Single Linked List

Input:
1
5
5 3 4 1 2
4

Output:
5 3 4 2

Explaination Recursive:

deleteNode(1639,2)
    deleteNode(639,1)
        deleteNode(412,2)
            deleteNode(12,1)
                return 2
            return 42
        return 342
    return 5342

*/
// Recursive Solution:
// Node *deleteNode(Node *head, int x)
// {
//     if (!head)
//     {
//         return NULL;
//     }
//     if (x == 1)
//     {
//         return head->next;
//     }
//     head->next = deleteNode(head->next, x - 1);
//     return head;
// }

// Iterative Solution:
struct Node *deleteNode(struct Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // If k is 1, delete the first node and return the new head
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else
    {
        // Initialize iterators
        Node *temp = head;
        Node *back;

        // Move temp and back pointers until reaching the kth node or the end of the list
        while (temp != NULL && k > 1)
        {
            back = temp;
            temp = temp->next;
            k--;
        }

        // Update the previous node's next pointer to skip the kth node, i.e. k = 1 is reached
        back->next = temp->next;
        free(temp);

        return head;
    }
}