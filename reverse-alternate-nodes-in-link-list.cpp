//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* A linked list node */

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

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert()
{
    int n, value;
    cin >> n;
    struct Node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
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
        }
    }
}

// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/

/*
Reverse alternate nodes in Link List

Input:
1
8
10 4 9 1 3 5 9 4

Output:
10 9 3 9 4 5 1 4

odd = 10 4 9 1 3 5 9 4

last = 4
first = 10 4 9 1 3 5 9 4
second = 4 9 1 3 5 9 4

while 1st Iteration:
    first = 10 9 1 3 5 9 4
        aliasing: odd = 10 9 1 3 5 9 4
    second = 4
    last = 4 4
        aliasing: odd = 10 9 1 3 5 9 4 4
        aliasing: first = 10 9 1 3 5 9 4 4
    first = 9 1 3 5 9 4 4
    second = 1 3 5 9 4 4


    2nd Iteration:
    first = 9 3 5 9 4 4
        aliasing: odd = 10 9 3 5 9 4 4
    second = 1 4 N
    last = 4 1 4
        aliasing: odd = 10 9 3 5 9 4 1
        aliasing: first = 9 3 5 9 4 1

    first = 3 5 9 4 1
    second = 5 9 4 1 4


    3rd Iteration:
    first = 9 9 4 1 4
        aliasing: odd = 10 9 3 9 4 1 4
    second = 5 1 4
    last = 4 5 1 4
        aliasing: odd = 10 9 3 9 4 5 1 4
        aliasing: first = 3 9 4 5 1 4
    first = 9 4 5 1 4
    second = 4 5 1 4

    4th Iteration:
    



*/

class Solution
{
public:
    void rearrange(struct Node *odd)
    {
        if (odd->next == NULL || odd->next->next == NULL)
        {
            return;
        }
        Node *last = odd;
        while (last->next)
        {
            last = last->next;
        }
        Node *first = odd, *second = odd->next;
        while (first != last && second != last)
        {
            first->next = second->next;
            second->next = last->next;
            last->next = second;
            first = first->next;
            second = first->next;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends