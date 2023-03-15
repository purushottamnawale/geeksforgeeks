//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        string temp = "";
        string result = "";
        for (int i = S.length() - 1; i >= 0; i--)
        {
            if (S[i] == '.')
            {
                result = result + temp + S[i];
                temp = "";
            }
            else
            {
                temp = S[i] + temp;
            }
        }
        result = result + temp;
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends