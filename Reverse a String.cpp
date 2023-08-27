//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << reverseWord(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++

/*
Reverse a String

Input:
1
Geeks

Output:
skeeG


Alternate Solution:
string reverseWord(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        swap(str[i++], str[j--]);
    }
    return str;
}

*/

string reverseWord(string str)
{
    string str1 = "";
    for (int i = str.size(); i >= 0; i--)
    {
        str1 += str[i];
    }
    return str1;
}

