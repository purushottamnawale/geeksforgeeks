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

// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

/*
Pairwise swap elements of a linked list

Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7

head = 1 2 2 4 5 6 7 8

pairWiseSwap(1 2 2 4 5 6 7 8)
    pairWiseSwap(2 4 5 6 7 8)
        pairWiseSwap(5 6 7 8)
            next = 8 7
            temp = 6 7 8
            pairWiseSwap(7 8)
                next = N
                temp = 8
                head = 7 N
                temp = 8 7
                head = 8 7
                return 8 7
                pairWiseSwap(N)
                    return NULL

*/

class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        if (head && head->next)
        {
            struct Node *next = pairWiseSwap(head->next->next);
            struct Node *temp = head->next;
            head->next = next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        map<Node *, int> mp;
        mp[head] = head->data;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
            mp[tail] = tail->data;
        }
        struct Node *failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        struct Node *temp = head;
        while (temp)
        {
            if (mp[temp] != temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
    }
    return 0;
}

// } Driver Code Ends