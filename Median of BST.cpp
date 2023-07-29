//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
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

float findMedian(struct Node *node);

// Function to Build Tree
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
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    // cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        // getline(cin, s);

        cout << findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
int countnodes(Node *n)
// this is the recursive function to find no of nodes
{
    if (n == NULL)
        return 0;
    return 1 + countnodes(n->left) + countnodes(n->right);
}

int find(Node *n, int i, int target, int &median)
{
    // this is the function to copy the target nodes data into median by doing inorder traversal
    if (n == NULL)
        return i;

    i = find(n->left, i, target, median);
    i++;

    if (i == target)
        median = n->data;
    // when we reach the target node node data is copied into median

    i = find(n->right, i, target, median);
    return i;
}

float findMedian(struct Node *root)
{
    int n = countnodes(root);
    if (n % 2 == 1)
    {
        // odd number of nodes in tree so 1+n/2 node is median

        int median = 0;
        find(root, 0, 1 + n / 2, median);
        return median;
    }
    else
    {
        // even number of nodes in tree so 1+n/2,n/2 are median nodes

        int median1 = 0, median2 = 0;
        find(root, 0, n / 2, median1);
        find(root, 0, 1 + n / 2, median2);
        float ans = median1 + median2;
        return ans / 2;
    }
}
