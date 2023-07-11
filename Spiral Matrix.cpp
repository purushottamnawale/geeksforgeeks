//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++) // for top
            {
                k--;
                if (k == 0)
                {
                    return a[top][i];
                }
            }
            top++;

            for (int i = top; i <= bottom; i++) // for right
            {
                k--;
                if (k == 0)
                {
                    return a[i][right];
                }
            }
            right--;

            // for bottom
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    k--;
                    if (k == 0)
                    {
                        return a[bottom][i];
                    }
                }
                bottom--;
            }

            // for left
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    k--;
                    if (k == 0)
                    {
                        return a[i][left];
                    }
                }
                left++;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        // cin>>k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        Solution obj;

        cout << obj.findK(a, n, m, k) << "\n";
    }
}
// } Driver Code Ends