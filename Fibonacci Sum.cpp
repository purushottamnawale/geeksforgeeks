//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int fibSum(long long int N)
    {
        long long int sum = 1, t1 = 0, t2 = 1, nextTerm;
        if (N == 0 || N == 1)
        {
            return N;
        }
        for (int i = 1; i < N; i++)
        {
            nextTerm = (t1 + t2) % 1000000007;
            sum += nextTerm;
            t1 = t2;
            t2 = nextTerm;
        }
        return sum % 1000000007;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0;
}
// } Driver Code Ends