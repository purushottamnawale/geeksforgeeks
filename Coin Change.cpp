//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int count(int S[], int m, int n)
    {
        vector<long long int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = S[i]; j <= n; j++)
            {
                dp[j] += dp[j - S[i]];
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends