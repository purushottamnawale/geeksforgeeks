//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

/*
Number of distinct subsequences


Input:
1
abcbac

output:
50


Explanation:
s = abcbac
ans = 1
mp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i = 'a'
    repeating_seq = mp[0] = 0
    mp[0] = 1
    mp = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 1 * 2 - 0 = 2


    i = 'b'
    repeating_seq = mp[1] = 0
    mp[1] = 2
    mp = [1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 2 * 2 - 0 = 4


    i = 'c'
    repeating_seq = mp[2] = 0
    mp[2] = 4
    mp = [1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 4 * 2 - 0 = 8


    i = 'b
    repeating_seq = mp[2] = 2
    mp[2] = 8
    mp = [1, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 8 * 2 - 2 = 14


    i = 'a
    repeating_seq = mp[0] = 1
    mp[0] = 14
    mp = [14, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 14 * 2 - 1 = 27


    i = 'c'
    repeating_seq = mp[2] = 4
    mp[2] = 27
    mp = [14, 8, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ans = 27 * 2 - 4 = 50
*/

class Solution
{
public:
    // TC: O(N) and SC: O(26):
    int distinctSubsequences(string s)
    {
        int ans = 1;
        int m = 1e9 + 7;
        int mp[26] = {0};
        for (char i : s)
        {
            int seq = mp[i - 'a']; // repeating sub-sequence
            mp[i - 'a'] = ans;
            ans = (1LL * ans * 2 - seq + m) % m;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.distinctSubsequences(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends

/*
Another Approach:
TC: O(N) and SC: O(N)
int distinctSubsequences(string str)
{
    vector<int> last(26, -1);

    int mod = 1e9 + 7;

    // Length of input string
    int n = str.size();

    // dp[i] is going to store count of distinct subsequences of length i.
    long long dp[n + 1];

    // Empty substring has only one subsequence
    dp[0] = 1;

    // Traverse through all lengths from 1 to n.
    for (int i = 1; i <= n; i++)
    {
        // Number of subsequences with substring str[0..i-1]
        dp[i] = 2 * dp[i - 1];

        dp[i] %= mod;

        // If current character has appeared before, then remove all subsequences ending with previous occurrence.
        if (last[str[i - 1] - 'a'] != -1)
        {
            dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + mod) % mod;
        }

        // Mark occurrence of current character
        last[str[i - 1] - 'a'] = (i - 1);
    }

    return (int)(dp[n]);
}


Explanation:
str = abcbac
n = 6
last = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

dp[0] = 1
dp = 1 0 0 0 0 0 0

for i = 1
    dp[1] = 2 * dp[0]
    dp = 1 2 0 0 0 0 0
    if last[0] != -1: false
    last[0] = 0
    last = [0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]


    i = 2
    dp[2] = 2 * dp[1]
    dp = 1 2 4 0 0 0 0
    if last[1] != -1: false
    last[1] = 1
    last = [0, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]


    i = 3
    dp[3] = 2 * dp[2]
    dp = 1 2 4 8 0 0 0
    if last[2] != -1: false
    last[2] = 2
    last = [0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]


    i = 4
    dp[4] = 2 * dp[3]
    dp = 1 2 4 8 16 0 0
    if last[2] != -1:
        dp[4]= dp[4] - dp[last[2]] = dp[4] - dp[2] = 16 - 2 = 14
        dp = 1 2 4 8 14 0 0
    last[1] = 3
    last = [0, 3, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]


    i = 5
    dp[5] = 2 * dp[4]
    dp = 1 2 4 8 14 28 0
    if last[0] != -1:
        dp[5]= dp[5] - dp[last[0]] = dp[5] - dp[0] = 28 - 1 = 27
        dp = 1 2 4 8 14 27 0
    last[1] = 3
    last = [4, 3, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

    i = 6
    dp[6] = 2 * dp[5]
    dp = 1 2 4 8 14 27 54
    if last[2] != -1:
        dp[6]= dp[6] - dp[last[2]] = dp[6] - dp[2] = 54 - 4 = 50
        dp = 1 2 4 8 14 27 50
    last[1] = 3
    last = [4, 3, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

*/