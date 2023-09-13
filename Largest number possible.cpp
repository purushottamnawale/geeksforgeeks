//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findLargest(int n, int S)
    {
        string res = "";
        if ((S <= 0 && n > 1) || (S > 9 * n))
            return "-1";
        for (int i = 0; i < n; i++)
        {
            if (S > 9)
            {
                res += '9';
                S -= 9;
            }
            else if (S <= 9)
            {
                res += to_string(S);
                S = 0;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends