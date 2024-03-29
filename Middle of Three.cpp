//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++


// If A > B > C then A-B and B-C will be positive.
// If A > C > B then A-C and C-B will be positive.

class Solution
{
public:
    int middle(int A, int B, int C)
    {
        long long int a = A, b = B, c = C;
        if ((a - b) * (b - c) > 0)
        {
            return B;
        }
        else if ((a - c) * (c - b) > 0)
        {
            return c;
        }
        else
        {
            return a;
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
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";
    }
    return 0;
}
// } Driver Code Ends