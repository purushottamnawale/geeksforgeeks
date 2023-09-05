//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int node1 = edges[i].first;
            int node2 = edges[i].second;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        return adj;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> edges;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for (int i = 0; i < V; i++)
        {
            sort(adj[i].begin(), adj[i].end());
            for (auto it : adj[i])
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends