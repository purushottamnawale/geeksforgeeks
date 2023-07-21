//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

/*
Reverse a Linked List in groups of given size

Example 1:
Input:
1 8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

Explanation:

Reverse( 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, 4)
    count = 0
    Prev = NULL
    Curr = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8
    Next = NULL

    While count < 4
        Next = 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8
        Curr = 1 -> NULL
        Prev = 1 -> NULL
        Curr = 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8
        count = 1

        Next = 2 -> 4 -> 5 -> 6 -> 7 -> 8
        Curr = 2 -> 1 -> NULL
        Prev = 2 -> 1 -> NULL
        Curr = 2 -> 4 -> 5 -> 6 -> 7 -> 8
        count = 2

        Next = 4 -> 5 -> 6 -> 7 -> 8
        Curr = 2 -> 2 -> 1 -> NULL
        Prev = 2 -> 2 -> 1 -> NULL
        Curr = 4 -> 5 -> 6 -> 7 -> 8
        count = 3

        Next = 5 -> 6 -> 7 -> 8
        Curr = 4 -> 2 -> 2 -> 1 -> NULL
        Prev = 4 -> 2 -> 2 -> 1 -> NULL
        Curr = 5 -> 6 -> 7 -> 8
        count = 4


    Head = 4 -> 2 -> 2 -> 1 -> Reverse(5 -> 6 -> 7 -> 8, 4)
        count = 0
        Prev = NULL
        Curr = 5 -> 6 -> 7 -> 8
        Next = NULL
        
        While count < 4
            Next = 6 -> 7 -> 8
            Curr = 5 -> NULL
            Prev = 5 -> NULL
            Curr = 6 -> 7 -> 8
            count = 1

            Next = 7 -> 8
            Curr = 6 -> 5 -> NULL
            Prev = 6 -> 5 -> NULL
            Curr = 7 -> 8
            count = 2

            Next = 8
            Curr = 7 -> 6 -> 5 -> NULL
            Prev = 7 -> 6 -> 5 -> NULL
            Curr = 8
            count = 3

            Next = NULL
            Curr = 8 -> 7 -> 6 -> 5 -> NULL
            Prev = 8 -> 7 -> 6 -> 5 -> NULL
            Curr = NULL
            count = 4
    
    Head = 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Example 2:
Input:
1 5
1 2 3 4 5 
3

Output:
3 2 1 5 4 
*/


class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        int count = 0;
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL)
        {
            head->next = reverse(next, k);
        }

        return prev;
    }
};

//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
            printList(head);
    }

    return (0);
}

// } Driver Code Ends