//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

/*
Given a linked list of 0s, 1s and 2s, sort it


Example 1)
Input:
1
8
1 2 2 1 2 0 2 2

Output:
0 1 1 2 2 2 2 2



Example 2)
Input:
1
9
2 1 2 1 1 2 0 1 0

Output:
0 0 1 1 1 1 2 2 2

Explaination:

zeroHead = -1 0 0
zeroTail =  0
oneHead  = -1 1 1 1 1 0
oneTail  =  1 0
twoHead  = -1 2 2 2 0 0
twoTail  =  2 0 0


zeroHead = -1 0 0
zeroTail =      0
oneHead  =     -1 1 1 1 1 0
oneTail  =              1 0
twoHead  =             -1 2 2 2 0 0
twoTail  =                    2 0 0


zeroHead = 0 0
zeroTail =   0
oneHead  =     1 1 1 1
oneTail  =           1
twoHead  =             2 2 2
twoTail  =                 2

0 0 1 1 1 1 2 2 2
*/

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *curr = head;

        while (curr)
        {
            if (curr->data == 0)
            {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            }
            else if (curr->data == 1)
            {
                oneTail->next = curr;
                oneTail = oneTail->next;
            }
            else if (curr->data == 2)
            {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }

            curr = curr->next;
        }

        if (oneHead->next)
        {
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
        }
        else
        {
            zeroTail->next = twoHead->next;
        }

        twoTail->next = NULL;

        head = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};

//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends