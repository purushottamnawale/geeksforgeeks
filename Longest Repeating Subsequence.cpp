//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Longest Repeating Subsequence:

Input:
1 abacbc

Output:
3

      0  1  2  3  4  5  6
      -  a  b  a  c  b  c

0 -   0  0  0  0  0  0  0
1 a   0  0  0  1  1  1  1
2 b   0  0  0  1  1  2  2
3 a   0  1  1  1  1  2  2
4 c   0  1  1  1  1  2  3
5 b   0  1  2  2  2  2  3
6 c   0  1  2  2  3  3  3

*/

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        string s = str;
        int n = str.size();
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == s[j - 1] && i != j) // LCS with itself, except i!=j
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends