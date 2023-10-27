//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int minimumNumberOfDeletions(string S)
    {
        string t = S;
        reverse(t.begin(), t.end());
        int n = S.length();

        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] == t[j - 1])
                {
                    curr[j] = 1 + pre[j - 1];
                    continue;
                }

                int a = pre[j];
                int b = curr[j - 1];

                curr[j] = max(a, b);
            }
            pre = curr;
        }

        return n - pre[n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends