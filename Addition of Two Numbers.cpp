//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int addition(int A, int B)
    {
        return A + B;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addition(A, B) << endl;
    }
    return 0;
}

// } Driver Code Ends