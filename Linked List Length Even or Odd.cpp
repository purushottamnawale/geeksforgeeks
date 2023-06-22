//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

// Function to check the length of linklist
int isLengthEvenOrOdd(struct Node *head);

// Driver function
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tmp, first, i, l;
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> first;
        head = new Node(first);
        tail = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        if (isLengthEvenOrOdd(head) == 0)
            cout << "Even\n";
        else
            cout << "Odd\n";
    }
    return 0;
}

// } Driver Code Ends

/*structure of a node of the linked list is as
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
// Function should return 0 is length is even else return 1

int isLengthEvenOrOdd(struct Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    if (length % 2 == 0)
    {
        return 0;
    }
    return 1;
}


/*
Alternate approach:
^ : XOR Operator


Example 1:
3
9 4 3

1 ^ L (4,3)            1 ^ 0 = 1
    1 ^ L (3)          1 ^ 1 = 0
        1 ^ L (NULL)   1 ^ 0 = 1
            0

Answer is 1 i.e. Odd


Example 2:
6
12 52 10 47 95 0

1 ^ L (52,10,47,95,0)              1 ^ 1 = 0
    1 ^ L (10,47,95,0)             1 ^ 0 = 1
        1 ^ L (47,95,0)            1 ^ 1 = 0
            1 ^ L (95,0)           1 ^ 0 = 1
                1 ^ L (0)          1 ^ 1 = 0
                    1 ^ L (NULL)   1 ^ 0 = 1
                        0
Anser is 0 i.e. Even

int isLengthEvenOrOdd(struct Node* head)
{
    if(head==NULL) return 0;
    return 1 ^ isLengthEvenOrOdd(head->next);
}

*/