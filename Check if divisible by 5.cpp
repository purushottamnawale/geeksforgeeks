//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int divisibleBy5(string N)
    {
        char ans = N[N.size() - 1];
        if (ans == '0' || ans == '5')
        {
            return 1;
        }
        else
        {
            return 0;
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
        string N;
        cin >> N;
        Solution ob;
        cout << ob.divisibleBy5(N) << endl;
    }
    return 0;
}
// } Driver Code Ends