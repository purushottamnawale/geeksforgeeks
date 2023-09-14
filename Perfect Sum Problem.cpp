//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int count_zeros_till_index(int arr[], int i) // returns the numberof zeros in array till index i
    {
        int count = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] == 0)
                count++;
        }
        return count;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        long long mod = 1e9 + 7;
        long long dp[n + 1][sum + 1];

        for (int i = 0, j = 0; j < sum + 1; j++)
            dp[i][j] = 0;
        for (int i = 0, j = 0; i < n + 1; i++)
        {
            dp[i][j] = pow(2, count_zeros_till_index(arr, i));
            // A little modification that is needed from Aditya verma's Code
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = ((dp[i - 1][j - arr[i - 1]]) % mod + (dp[i - 1][j]) % mod) % mod;
                }
                else
                    dp[i][j] = dp[i - 1][j] % mod;
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends