//{ Driver Code Starts
//

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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

/*
Insert in a Sorted List


Input:
1
6
25 36 47 58 69 80
75


Output:
25 36 47 58 69 75 80


*/

class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node *head, int data)
    {
        struct Node *new_node = new Node(data);
        if (head == NULL || head->data >= data)
        {
            // If new node is needed at the start of list
            new_node->next = head;
            return new_node;
        }
        Node *current = head;

        // Finding a node which has lesser value than new_node, but its successor should have greater or equal value
        while (current->next != NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        // Inserting new node after current node
        new_node->next = current->next;
        current->next = new_node;

        return head;
    }
};

//{ Driver Code Starts.
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
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        Solution obj;
        head = obj.sortedInsert(head, k);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends