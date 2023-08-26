//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Backend complete function template for C++

/*
Longest K unique characters substring


Input:
1
aabacbebebe
3

Output:
7
*/

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> m;
        int uniq = 0;     // To keep a count of distinct characters
        int i = 0, j = 0; // Starting and ending pointers
        int ans = 0;
        int n = s.length();

        while (j < n)
        {
            // Sliding the j-pointer till we have a valid substring
            while (j < n)
            {
                if (m[s[j]] == 0)
                {
                    uniq++;
                }
                m[s[j]]++;
                if (uniq > k) // If the number of unique characters are more than k, we stop.
                {
                    break;
                }
                j++;
            }

            // Checking if the unique characters are equal to k or k + 1
            if (uniq >= k)
            {
                ans = max(ans, j - i);
            }

            if (j == n)
            {
                break;
            }

            // Sliding the i-pointer till we again get k unique characters in the substring
            while (i < n)
            {
                if (m[s[i]] == 1)
                {
                    uniq--;
                }
                m[s[i]]--;

                if (uniq == k)
                {
                    break;
                }
                i++;
            }
            i++;
            j++;
        }
        if (ans == 0)
        {
            return -1;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends