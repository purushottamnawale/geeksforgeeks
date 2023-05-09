//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void toBinary(int N)
{
    int ans = 0, base = 1;
    while (N)
    {
        ans = ans + (N % 2) * base;
        base = base * 10;
        N = N / 2;
    }
    cout << ans;
}

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        toBinary(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends