//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree

// } Driver Code Ends
// Function to find the lowest common ancestor in a BST.

/*
Lowest Common Ancestor in a BST:

Example 1:
Input:
1
5 4 6 3 N N 7 N N N 8
7 8
1

Output:
7

Example 2:
Input:
1
20 8 22 4 12 N N N N 10 14
4 12
1

Output:
8


Another Apporoach: Recursive

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL) // base case
    {
        return NULL;
    }

    if (n1 < root->data and n2 < root->data) // If both n1 and n2 are smaller than data at current node, we call the function recursively for finding LCA in the left subtree.
    {
        return LCA(root->left, n1, n2);
    }
    if (n1 > root->data and n2 > root->data) // If both n1 and n2 are greater than data at current node, we call the function recursively for finding LCA in the right subtree.
    {
        return LCA(root->right, n1, n2);
    }

    return root;
}

*/
class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2)
    {
        Node *temp = root;
        if (!root)
        {
            return root;
        }
        while (temp)
        {
            if (n1 < temp->data && n2 < temp->data)
            {
                temp = temp->left;
            }
            else if (n1 > temp->data && n2 > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                return temp;
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node *root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout << ans << endl;
    }
    return 1;
}
// } Driver Code Ends