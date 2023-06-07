//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        vector<int> lpf(n + 1);
        lpf[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            lpf[i] = i;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (lpf[i] == i)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (lpf[j] == j)
                    {
                        lpf[j] = i;
                    }
                }
            }
        }
        return lpf;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.leastPrimeFactor(n);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends