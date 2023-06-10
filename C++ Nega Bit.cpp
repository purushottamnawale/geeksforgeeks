//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
2 = 010
5 = 101
7 = 111 = 2 ^ 5

21 = 010101
55 = 110111
34 = 100010 = 21 ^ 55
*/
class Solution
{
public:
    int negaBit(int F, int S)
    {
        return F ^ S;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int F, S;

        cin >> F >> S;

        Solution ob;
        cout << ob.negaBit(F, S) << endl;
    }
    return 0;
}
// } Driver Code Ends