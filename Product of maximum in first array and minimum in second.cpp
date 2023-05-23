//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long find_multiplication(int a[], int b[], int n, int m)
    {
        long long int maxNo = INT_MIN, minNo = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            maxNo = max(static_cast<long long int>(a[i]), maxNo);
        }
        for (int j = 0; j < m; j++)
        {
            minNo = min(static_cast<long long int>(b[j]), minNo);
        }
        return maxNo * minNo;
    }

    long long find_multiplication(int a[], int b[], int n, int m)
    {
        return *max_element(a, a + n) * *min_element(b, b + m);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.find_multiplication(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends