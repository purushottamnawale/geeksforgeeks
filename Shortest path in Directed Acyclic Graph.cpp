//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    // Topological sort
    vector<int> stak;
    void DFS_Topo_sort(int node, vector<vector<int>> adj[], vector<int> &visited)
    {
        visited[node] = true;

        for (auto nbr : adj[node])
        {
            if (!visited[nbr[0]])
                DFS_Topo_sort(nbr[0], adj, visited);
        }
        stak.push_back(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj[N];
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }
        // finding Toposort
        vector<int> visited(N), distance(N, INT_MAX);
        DFS_Topo_sort(0, adj, visited);
        // reverse(stak.begin() , stak.end()) ;

        distance[0] = 0;
        while (stak.size())
        {
            int node = stak.back();
            stak.pop_back();

            for (auto &nbrData : adj[node])
            {
                int nbr = nbrData[0];
                int wt = nbrData[1];
                if (distance[node] + wt < distance[nbr])
                {
                    distance[nbr] = distance[node] + wt;
                }
            }
        }
        for (auto &d : distance)
            if (d == INT_MAX)
                d = -1;

        return distance;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends