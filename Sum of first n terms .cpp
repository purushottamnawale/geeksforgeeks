//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

/*
1^3 + 2^3 + 3^3 + 4^3 + ... + N^3 = (N * (N + 1) / 2) ^ 2
                                  = (N * N *(N + 1) * (N + 1)) / 4

Alternate Solution:
long long sumOfSeries(long long N)
{
    return (N * N *(N + 1) * (N + 1)) / 4;
}

The above program causes overflow, even if result is not beyond integer limit. 
We can avoid overflow upto some extent by doing division first. 

*/

class Solution
{
public:
    long long sumOfSeries(long long N)
    {
        long long int x;
        if (N % 2 == 0)
        {
            x = (N / 2) * (N + 1);
        }
        else
        {
            x = ((N + 1) / 2) * N;
        }
        return x * x;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends