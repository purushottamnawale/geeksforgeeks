//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Just a normal function for checking palindrome
    bool isPalin(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int palindromicPartition(string str)
    {

        int N = str.size();

        int t[N + 1] = {0};

        t[N] = 0;

        for (int i = N - 1; i >= 0; i--)
        {

            int mini = INT_MAX;

            for (int j = i; j < N; j++)
            {

                if (isPalin(str, i, j))
                {

                    int ans = 1 + t[j + 1];

                    mini = min(mini, ans);
                }

                t[i] = mini;
            }
        }
        return t[0] - 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends