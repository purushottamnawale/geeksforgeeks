//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int n, m;

    // To traverse four directions of grid
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};

    // To check whether coordinate lies inside the grid
    bool isValid(int ni, int nj)
    {
        if (ni >= 0 && nj >= 0 && ni < n && nj < m)
            return true;
        return false;
    }

    // To calculate size of each island in the grid.
    // For every island we are using a key. We are filling the visited array with this key,
    // so that we can get the size of island easily afterwards.
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int &key)
    {
        vis[i][j] = key;
        int sz = 1;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (isValid(ni, nj) && !vis[ni][nj] && grid[ni][nj])
            {
                sz += dfs(ni, nj, grid, vis, key);
            }
        }

        return sz;
    }
    // main function
    int largestIsland(vector<vector<int>> &grid)
    {
        // Your code goes here.
        n = grid.size();
        m = grid[0].size();
        int mx = 0, key = 1;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        map<int, int> mp;
        // Map stores key - size relation in it
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    key++;
                    int sz = dfs(i, j, grid, vis, key);
                    mp[key] = sz;
                    mx = max(mx, sz);
                }
            }
        }

        // now traverse grid and if you find any zero change it to one and
        // then observe what will be its impact on existing size of island.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int newSize = 1;
                    set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k];
                        int nj = j + dj[k];

                        if (isValid(ni, nj) && grid[ni][nj])
                        {
                            st.insert(vis[ni][nj]);
                        }
                    }
                    for (auto it : st)
                    {
                        newSize += mp[it];
                    }
                    mx = max(mx, newSize);
                }
            }
        }

        // return maximum size island.
        return mx;
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
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        Solution ob;
        cout << ob.largestIsland(grid) << endl;
    }
    return 0;
}

// } Driver Code Ends