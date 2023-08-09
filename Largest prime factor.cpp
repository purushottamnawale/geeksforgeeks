//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int largestPrimeFactor(int n)
    {
        long long int i = 2;
        while ((i * i) <= n) // Loop till sqrt(n)
        {
            if (n % i == 0) // If i divides n evenly then divide n by i
            {
                n /= i;
            }
            else
            {
                i++; // increase i if it don't divide n
            }
        }
        return n;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0;
}
// } Driver Code Ends