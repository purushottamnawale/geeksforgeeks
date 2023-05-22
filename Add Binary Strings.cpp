//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string addBinary(string A, string B)
    {
        // Keep the larger string in B
        if (A.length() > B.length())
        {
            swap(A, B);
        }

        int diff = B.length() - A.length();

        // Add zeros to smaller string to make both strings of equal length
        for (int i = 0; i < diff; i++)
        {
            A = '0' + A;
        }

        string ans;
        char carry = '0';
        for (int i = A.length() - 1; i >= 0; i--)
        {
            if (A[i] == '1' && B[i] == '1')
            {
                if (carry == '1')
                {
                    ans.push_back('1'), carry = '1';
                }
                else
                {
                    ans.push_back('0'), carry = '1';
                }
            }
            else if (A[i] == '0' && B[i] == '0')
            {
                if (carry == '1')
                {
                    ans.push_back('1'), carry = '0';
                }
                else
                {
                    ans.push_back('0'), carry = '0';
                }
            }
            else
            {
                if (carry == '1')
                {
                    ans.push_back('0'), carry = '1';
                }
                else
                {
                    ans.push_back('1'), carry = '0';
                }
            }
        }
        if (carry == '1')
        {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());

        // To remove leading zeroes
        int index = 0;
        while (index + 1 < ans.length() && ans[index] == '0') // index + 1 < ans.length() is used to avoid removing all zeroes in case of ans = "0"
        {
            index++;
        }

        return ans.substr(index);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends