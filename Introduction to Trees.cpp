//{ Driver Code Starts
// Initial Template for C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// } Driver Code Ends
// User function Template for C++

/*
The maximum number of nodes at level ‘l’ of a binary tree is 2^l: 
Note: Here, level is the number of nodes on the path from the root to the node (including root and node).
The level of the root is 0.
*/

class Solution
{
public:
    int countNodes(int i)
    {
        return pow(2, i - 1); // This Question considers root as level 1, hence i-1.
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}

// } Driver Code Ends