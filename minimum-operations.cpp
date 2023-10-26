//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minOperation(int n)
    {
        int ans = 0;
        while (n)
        {
            if (!(n % 2))
                n /= 2;
            else
                n--;

            ans++;
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
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
}
// } Driver Code Ends