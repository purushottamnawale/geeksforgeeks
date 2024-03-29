//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

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

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*
Delete nodes having greater value on right


Input:
1
8
12 15 10 11 5 6 2 3

Output:
15 11 6 3

12 15 10 11 5 6 2 3

Explanation of First Approach:

First iteration until the condition is satisfied
    curr 12 15 10 11 5 6 2 3
    head 12 15 10 11 5 6 2 3
    curr 15 15 10 11 5 6 2 3
    head 15 15 10 11 5 6 2 3
    curr 15 10 11 5 6 2 3
    head 15 10 11 5 6 2 3
    curr 15 10 11 5 6 2 3

curr 10 11 5 6 2 3

Second iteration until the condition is satisfied
    curr 10 11 5 6 2 3
    head 15 10 11 5 6 2 3
    curr 11 11 5 6 2 3
    head 15 11 11 5 6 2 3
    curr 11 5 6 2 3
    head 15 11 5 6 2 3
    curr 15 11 5 6 2 3

curr 5 6 2 3

Third iteration until the condition is satisfied
    curr 5 6 2 3
    head 15 11 5 6 2 3
    curr 6 6 2 3
    head 15 11 6 6 2 3
    curr 6 2 3
    head 15 11 6 2 3
    curr 15 11 6 2 3

curr 2 3

Fourth iteration until the condition is satisfied
    curr 2 3
    head 15 11 6 2 3
    curr 3 3
    head 15 11 6 3 3
    curr 3
    head 15 11 6 3
    curr 15 11 6 3



Explanation of Second  approach:
Time Complexity O(N)

head 12 15 10 11 5 6 2 3
curr 12 15 10 11 5 6 2 3
prev N
next N

After Reverse
head 3 2 6 5 11 10 15 12
prev 3 2 6 5 11 10 15 12
curr N
next N

current 3 2 6 5 11 10 15 12
maxNode 3 2 6 5 11 10 15 12

First Iteration 2 < 3
temp    2 6 5 11 10 15 12
current 3 6 5 11 10 15 12
maxNode 3 6 5 11 10 15 12
head    3 6 5 11 10 15 12

Second Iteration 6 < 3 false
current 6 5 11 10 15 12
maxNode 6 5 11 10 15 12
head    3 6 5 11 10 15 12

Third Iteration 5 < 6
temp    5 11 10 15 12
current 6 11 10 15 12
maxNode 6 11 10 15 12
head    3  6 11 10 15 12

Fourth Iteration 11 < 6 false
current 11 10 15 12
maxNode 11 10 15 12
head     3  6 11 10 15 12

Fifth Iteration 10 < 11
temp    10 15 12
current 11 15 12
maxNode 11 15 12
head     3  6 11 15 12

Sixth Iteration 15 < 11 false
current 15 12
maxNode 15 12
head     3  6 11 15 12

Seventh Iteration 12 < 15
temp    12
current 15
maxNode 15
head     3  6 11 15

curr 3 6 11 15
prev N
next N
current 15
maxNode 15
head 3 6 11 15

After Reverse
curr N
next N
prev    15 11 6 3
current 15 11 6 3
maxNode 15 11 6 3
head    15 11 6 3



*/

class Solution
{
public:
    // Node *compute(Node *head)
    // {
    //     Node *curr = head;
    //     while (curr->next)
    //     {
    //         if (curr->data < curr->next->data)
    //         {
    //             curr->data = curr->next->data;
    //             Node *temp = curr->next;
    //             curr->next = curr->next->next;
    //             delete temp;
    //             curr = head;
    //         }
    //         else
    //         {
    //             curr = curr->next;
    //         }
    //     }
    //     return head;
    // }

    Node *Reverse(Node *head)
    {
        Node *cur = head;
        Node *prev = NULL;
        Node *next;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }

    Node *compute(Node *head)
    {
        head = Reverse(head);

        Node *current = head;
        Node *maxNode = head;
        Node *temp;

        while (current != NULL && current->next != NULL)
        {
            if (current->next->data < maxNode->data)
            {
                temp = current->next;
                current->next = temp->next;
                free(temp);
            }
            else
            {
                current = current->next;
                maxNode = current;
            }
        }

        return Reverse(head);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

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
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends