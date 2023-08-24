//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Multiply two strings

Example 1)
Input:
1
0033 2

Output:
66

Example 2)
Input:
1
011
0023

Output:
253


Method of Multiplication used here is different
 28
x
 39
____
1092

0   0    0   72   //72
0   0    7   72
0   0    7    2 
0   0   31    2   //24
0   3   31    2
0   3    1    2
0   3   19    2   //18
0   4   19    2
0   4    9    2
0  10    9    2   //6
1  10    9    2
1   0    9    2

*/

class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        // Edge case
        if (s1 == "0" || s2 == "0")
        {
            return "0";
        }

        // To check the negative digits
        bool neg1 = false;
        bool neg2 = false;
        if (s1[0] == '-')
        {
            neg1 = true;
            s1[0] = '0';
        }
        if (s2[0] == '-')
        {
            neg2 = true;
            s2[0] = '0';
        }

        // Declaring an vector of size of total no of digits in (s1 + s2) and intitializing it with 0
        vector<int> ans_vector(s1.size() + s2.size(), 0);

        // Build the ans by multiplying one digit at the time
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                ans_vector[i + j + 1] += (s1[i] - '0') * (s2[j] - '0'); // += To add the carry
                ans_vector[i + j] += ans_vector[i + j + 1] / 10;        // Putting the carry at it's position, which will be added by above line in next iteration
                ans_vector[i + j + 1] %= 10;
            }
        }

        // There might be some leading 0's in vector, which are not needed
        int i = 0;
        while (i < ans_vector.size() && ans_vector[i] == 0)
        {
            i++;
        }

        // Converting the vector to string
        string ans = "";
        if ((neg1 == true && neg2 == false) || (neg1 == false && neg2 == true)) // If one is positive and one is negative
        {
            ans.push_back('-');
        }

        while (i < ans_vector.size())
        {
            ans.push_back(ans_vector[i] + '0');
            i++;
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
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
}
// } Driver Code Ends