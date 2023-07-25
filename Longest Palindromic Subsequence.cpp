//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Longest Palindromic Subsequence:

Input:
1 bbabcbcab

Output:
7

      0  1  2  3  4  5  6  7  8  9
      -  b  a  c  b  c  b  a  b  b

0 -   0  0  0  0  0  0  0  0  0  0
1 b   0  1  1  1  1  1  1  1  1  1
2 b   0  1  1  1  2  2  2  2  2  2
3 a   0  1  2  2  2  2  2  3  3  3
4 b   0  1  2  2  3  3  3  3  4  4
5 c   0  1  2  3  3  4  4  4  4  4
6 b   0  1  2  3  4  4  5  5  5  5
7 c   0  1  2  3  4  5  5  5  5  5
8 a   0  1  2  3  4  5  5  6  6  6
9 b   0  1  2  3  4  5  6  6  7  7
*/

class Solution
{
public:
    int longestPalinSubseq(string A)
    {
        int n = A.length();
        string B(A.rbegin(), A.rend()); // reverse of string A;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends