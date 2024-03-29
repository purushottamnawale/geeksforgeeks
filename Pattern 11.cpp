//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
Put 1 at odd positions (i + j = 1, 3, 5) and 0 at even positions (i + j = 2, 4, 6)

   0 1 2 3 4
1  1
2  0 1
3  1 0 1
4  0 1 0 1
5  1 0 1 0 1
*/

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << (i + j) % 2 << " ";
            }
            cout << endl;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends