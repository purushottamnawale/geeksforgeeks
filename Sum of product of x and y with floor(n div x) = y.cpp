//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int sumofproduct(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i * (n / i);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        long long int ans = ob.sumofproduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends