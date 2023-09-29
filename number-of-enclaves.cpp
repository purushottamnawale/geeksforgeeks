//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

/*
Number Of Enclaves

Input:
1
5 4
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0

Output:
3
*/

class Solution
{
public:
    // Function to perform depth-first search to mark all connected 1's as 0's.
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        // If the current cell is out of bounds or has already been visited or is a 0, return.
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0)
        {
            return;
        }

        // Mark the current cell as 0 and recursively call dfs on adjacent cells.
        grid[i][j] = 0;
        dfs(i + 1, j, grid); // down
        dfs(i, j + 1, grid); // right
        dfs(i, j - 1, grid); // left
        dfs(i - 1, j, grid); // up
    }

    // Function to count the number of enclaves.
    int numberOfEnclaves(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        // Perform DFS on all the border cells and mark all the connected 1's as 0's
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }

        // Count the remaining 1's in the grid which are not connected to the borders.
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count += grid[i][j];
            }
        }

        // Return the count of enclaves.
        return count;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends