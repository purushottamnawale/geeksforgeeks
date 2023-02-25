//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cppIntType()
    {
        int a;
        cin >> a;
        return a;
    }

    char cppCharType()
    {
        char b;
        cin >> b;
        return b;
    }

    float cppFloatType()
    {
        float c;
        cin >> c;
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cout << ob.cppIntType() << endl;
        cout << ob.cppCharType() << endl;
        cout << ob.cppFloatType() << endl;
    }
    return 0;
}
// } Driver Code Ends