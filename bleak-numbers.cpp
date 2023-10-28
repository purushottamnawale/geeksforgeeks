//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        int count = 0;
        while (n)
        {
            count++;
            n = (n & (n - 1));
        }
        return count;
    }

    int is_bleak(int n)
    {
        for (int i = max(n - 32, 1); i < n; i++)
            if (i + countSetBits(i) == n)
                return 0;
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.is_bleak(n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends