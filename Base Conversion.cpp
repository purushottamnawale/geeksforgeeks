//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string decimalToBinary(int a)
    {
        string ans;
        while (a)
        {
            ans = to_string(a % 2) + ans;
            a = a / 2;
        }
        return ans;
    }

    string binaryToDecimal(int b)
    {
        int ans = 0, base = 1;
        while (b)
        {
            ans += (b % 10) * base;
            base *= 2;
            b /= 10;
        }
        return to_string(ans);
    }

    string binaryToHexadecimal(int c)
    {
        string ans = "";
        char ch;
        while (c)
        {
            int rem = c % 16;
            if (rem < 10)
            {
                ch = rem + '0';
            }
            else
            {
                ch = rem - 10 + 'A';
            }
            ans = ch + ans;
            c = c / 16;
        }
        return ans;
    }

    string hexadecimalToDecimal(string d)
    {
        int ans = 0, base = 1;
        for (int i = d.size() - 1; i >= 0; i--)
        {
            if ('0' <= d[i] && d[i] <= '9')
            {
                ans = ans + base * (d[i] - '0');
            }
            else if ('A' <= d[i] && d[i] <= 'Z')
            {
                ans = ans + base * (d[i] - 'A' + 10);
            }
            base = base * 16;
        }
        return to_string(ans);
    }

    vector<string> convert(int a, int b, int c, string d)
    {
        vector<string> v;

        v.push_back(decimalToBinary(a));
        v.push_back(binaryToDecimal(b));
        v.push_back(binaryToHexadecimal(c));
        v.push_back(hexadecimalToDecimal(d));
        return v;
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
        string d;
        cin >> a >> b >> c >> d;

        Solution ob;
        vector<string> ans = ob.convert(a, b, c, d);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends