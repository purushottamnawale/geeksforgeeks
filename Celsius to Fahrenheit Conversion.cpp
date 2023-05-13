//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double celciusToFahrenheit(int C)
    {
        return C * 9 / 5.0 + 32;
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
        cout << setprecision(2) << fixed << ob.celciusToFahrenheit(N) << endl;
    }
    return 0;
}
// } Driver Code Ends