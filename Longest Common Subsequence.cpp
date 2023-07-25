//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

/*
Longest Common Subsequence:

Input:
1 6 6
ABCDGH
AEDFHR

Output:
3

      0  1  2  3  4  5  6
      -  A  E  D  F  H  R
                         
0 -   0  0  0  0  0  0  0
1 A   0  1  1  1  1  1  1
2 B   0  1  1  1  1  1  1
3 C   0  1  1  1  1  1  1
4 D   0  1  1  2  2  2  2
5 G   0  1  1  2  2  2  2
6 H   0  1  1  2  2  3  3



*/

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1]; // dp[column][row]

        for (int i = 0; i <= x; i++) // Initialize first column with 0
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= y; i++) // Initialize first row with 0
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                dp[i][j] = 0;
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends