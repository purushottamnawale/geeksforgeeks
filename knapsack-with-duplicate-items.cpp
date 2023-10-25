//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[1001][1001];
    int solve(int N, int W, int val[], int wt[])
    {
        if (N == 0 || W == 0)
            return 0;
        if (dp[N][W] != -1)
            return dp[N][W];
        if (wt[N - 1] <= W)
        {
            return dp[N][W] = max({val[N - 1] + solve(N, W - wt[N - 1], val, wt), solve(N - 1, W, val, wt)});
        }
        else
            return dp[N][W] = solve(N - 1, W, val, wt);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends