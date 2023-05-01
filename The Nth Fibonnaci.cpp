//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int fib(int N)
    {
        int nextTerm, t1 = 0, t2 = 1;
        if (N == 0 or N == 1)
        {
            return N;
        }

        for (int i = 1; i < N; i++)
        {
            nextTerm = (t1 + t2) % 10;
            t1 = t2;
            t2 = nextTerm;
        }
        return nextTerm % 10;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0;
}
// } Driver Code Ends