//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string armstrongNumber(int n)
    {
        int sum = 0;
        int originaln = n;

        while (n > 0)
        {
            int lastdigit = n % 10;
            sum += round(pow(lastdigit, 3));
            n = n / 10;
        }
        if (originaln == sum)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends