//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        long long int nextTerm, t1 = 0, t2 = 1;
        vector<long long> v;
        v.push_back(t2);

        for (int i = 1; i < n; i++)
        {
            nextTerm = t1 + t2;
            v.push_back(nextTerm);
            t1 = t2;
            t2 = nextTerm;
        }
        return v;
    }
};

/* Another Approach with lower syntax

vector<long long> printFibb(int n)
{
    // code here
    vector<long long> v(n);
    v[0] = v[1] = 1;
    for (int i = 2; i < n; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    return v;
}*/

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of elements
        int n;
        cin >> n;
        Solution obj;
        // calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        // printing the elements of vector
        for (long long i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends