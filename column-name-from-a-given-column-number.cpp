//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Column name from a given column number

Input:
1
28

Output:
AB

Explanation:
while 28:
    n = 28 - 1 = 27
    temp = 27 % 26 = 1
    ans += 'A' + 1 = 'B'
    n = 27 / 26 = 1

    1:
    n = 1 - 1 = 0
    temp = 0 % 26 = 0
    ans += 'A' + 0 = 'BA'
    n = 0 / 26 = 0

ans = reverse(ans)
ans = 'AB'
*/

class Solution
{
public:
// TC: O(logn) and SC: O(1)
string colName(long long int n)
{
    string ans = "";

    int temp;
    while (n)
    {
        n--;
        temp = n % 26;
        ans += ('A' + temp);
        n /= 26;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}

// } Driver Code Ends