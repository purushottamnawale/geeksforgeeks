//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int modulo(string s, int m)
    {
        int ans = 0, base = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ans += base;
            }
            ans %= m;
            base *= 2;
            base %= m;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int m;
        cin >> s >> m;
        Solution a;
        cout << a.modulo(s, m) << endl;
    }
    return 0;
}
// } Driver Code Ends