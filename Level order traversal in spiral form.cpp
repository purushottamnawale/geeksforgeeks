//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

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
    Node *root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

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
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    bool flag = false;
    queue<Node *> q;
    q.push(root);
    while (q.size()) // while queue is not empty
    {
        int n = q.size(); // number of nodes in current level
        stack<int> s;
        for (int i = 0; i < n; i++) // for each level
        {
            Node *temp = q.front();
            q.pop();
            if (flag == true)
            {
                ans.push_back(temp->data); // if traversal is from left to right, then push the element in ans
            }
            else
            {
                s.push(temp->data); // if traversal is from right to left, then push the element in stack
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        while (s.size()) // while stack has some elements
        {
            ans.push_back(s.top());
            s.pop();
        }
        flag = !flag; // change the direction of traversal
    }
    return ans;
}

/*
Another Approach: Recursive

int height(struct Node *root)
{
    // base case for recursion.
    if (root == NULL)
        return 0;

    // finding height of left subtree recursively.
    int l = 1 + height(root->left);

    // finding height of right subtree recursively.
    int r = 1 + height(root->right);

    // taking the maximum as height of tree.
    if (l > r)
        return l;
    else
        return r;
}

// Function to do level order traversal of tree in spiral form.
void spiral(vector<int> &ans, struct Node *root, int level, int flag)
{
    if (root == NULL) // base case for recursion
        return;

    if (level == 1) // if level is 1, we push the data in the ans vector
    {
        ans.push_back(root->data);
    }

    else if (level > 1)
    {
        if (flag) // if flag is true, we call the spiral function recursively for the left subtrees first and then for right subtrees.
        {
            spiral(ans, root->left, level - 1, flag);
            spiral(ans, root->right, level - 1, flag);
        }

        else // else we call for right subtrees first and then left subtrees.
        {
            spiral(ans, root->right, level - 1, flag);
            spiral(ans, root->left, level - 1, flag);
        }
    }
}

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(struct Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    int h = height(root);
    bool flag = false;

    for (int i = 1; i <= h; i++) // for each level, we do the spiral traversal
    {
        spiral(ans, root, i, flag);
        flag = !flag;
    }

    return ans;
}

*/