//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

/*
Roman Number to Integer

Input:
1 XXIV

Ouput:
24

Explanation:
str = "XXIV"
ans = 0

num = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}

for i = 3
    if num['V'] < str["does not exist"] => false
    else
        ans = 0 + 5 = 5
    

    i = 2
    if num['I'] < str['V'] => true
        ans = 5 - 1 = 4


    i = 1
    if num['X'] < str['I'] => false
    else
        ans = 4 + 10 = 14


    i = 0
    if num['X'] < str['X'] => false
    else
        ans = 14 + 10 = 24

*/

class Solution
{
public:
    // TC: O(N) and SC: O(1), here N is the length of the string
    int romanToDecimal(string &str)
    {
        int ans = 0;
        unordered_map<char, int> num;
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;

        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (num[str[i]] < num[str[i + 1]])
                ans -= num[str[i]];
            else
            {
                ans += num[str[i]];
            }
        }
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends