//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int Count(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int ans = 0;
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    int count = 0;
                    for (auto &v : directions)
                    {
                        int x = i + v[0];
                        int y = j + v[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 0)
                        {
                            count++;
                        }
                    }
                    if (count != 0 && count % 2 == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        int ans = ob.Count(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends