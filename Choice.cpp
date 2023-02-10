//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> arrayForm(int a, int b, int c)
    {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }

    string stringForm(int a, int b, int c)
    {
        return to_string(a) + to_string(b) + to_string(c);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Solution obj;
        vector<int> res = obj.arrayForm(a, b, c);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
        cout << obj.stringForm(a, b, c) << "\n";
    }
    return 0;
}
// } Driver Code Ends