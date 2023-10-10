//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
Nodes at given distance in binary tree

*/

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

// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
public:
    unordered_map<Node *, Node *> mp;
    Node *x = NULL;

    void InOrder(Node *root, int target)
    {
        if (!root)
            return;
        if (root->data == target)
        {
            x = root;
        }
        if (root->left)
        {

            mp[root->left] = root;
            InOrder(root->left, target);
        }

        if (root->right)
        {
            mp[root->right] = root;
            InOrder(root->right, target);
        }
    }
    void Bfs(Node *root, int k, vector<int> &ans)
    {
        queue<Node *> q;
        unordered_set<int> vis;
        vis.insert(root->data);
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            if (k == 0)
            {
                break;
            }
            while (n--)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left && !vis.count(temp->left->data))
                {
                    q.push(temp->left);
                    vis.insert(temp->left->data);
                }
                if (temp->right && !vis.count(temp->right->data))
                {
                    q.push(temp->right);

                    vis.insert(temp->right->data);
                }
                if (mp.count(temp) && !vis.count(mp[temp]->data))
                {
                    q.push(mp[temp]);

                    vis.insert(mp[temp]->data);
                }
            }
            k--;
        }
        while (!q.empty())
        {
            Node *tem = q.front();
            q.pop();
            ans.push_back(tem->data);
        }
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;              // ans vector to store result
        InOrder(root, target);        // Calculate the Inorder
        Bfs(x, k, ans);               // Calculate the Bfs
        sort(ans.begin(), ans.end()); // Sort the ans
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends