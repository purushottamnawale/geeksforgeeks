//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int factorial(int N)
    {
        long long int fact = 1;
        for (long long int i = N; i >= 1; i--)
        {
            fact *= i;
        }
        return fact;
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
        cout << ob.factorial(N) << endl;
    }
    return 0;
}
// } Driver Code Ends