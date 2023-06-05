//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
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

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// } Driver Code Ends
// User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution
{
public:
    Node *insertionSort(struct Node *head_ref)
    {
        Node *res = new Node(-1); // Create a new list to serve as the result
        Node *temp = res;         // Create a temporary list to traverse the result list
        Node *curr = head_ref;    // Create a current list to traverse the original list

        while (curr) // Iterate through the original list
        {
            temp = res; // Reset the temporary list to the beginning of the result list for each iteration

            // Find the correct position to insert the current node in the result list
            while (temp->next && temp->next->data <= curr->data)
            {
                temp = temp->next;
            }

            Node *nextNode = temp->next; // Temporarily store the second part of the result list in order to connect it later with the first part.

            temp->next = curr; // Insert the current node at the correct position in the sorted list (result list)

            curr = curr->next; // Move to the next node in the current list

            temp->next->next = nextNode; // Connect the first part of the result list with the second part
        }

        return res->next; // Return the sorted result list
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++)
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

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends