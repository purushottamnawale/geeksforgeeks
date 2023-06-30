//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int divisibleBy4(string N)
    {
        int num;
        if (N.size() > 2)
        {
            string lastTwoDigits = N.substr(N.size() - 2);
            num = stoi(lastTwoDigits);
        }
        else
        {
            num = stoi(N);
        }

        if (num % 4 == 0)
        {
            return 1;
        }
        return 0;
    }
};

/*
Alternate Solution:
int divisibleBy4(string N)
{
    return !(stoi(N.size() > 2 ? N.substr(N.size() - 2) : N) % 4);
}
*/

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.divisibleBy4(s) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends