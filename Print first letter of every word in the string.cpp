//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string firstAlphabet(string S)
    {
        int i = 0;
        cout << S[i];
        while (i < S.size())
        {
            if (S[i] == ' ')
            {
                cout << S[i + 1];
            }
            i++;
        }
    }
};

/*
Alternate Solution
string firstAlphabet(string S)
	{
	    cout<<S[0];
	    for(int i=0;i<S.length();i++){
	        if(S[i]==32){
	            cout<<S[i+1];
	        }
	    }
	}
*/

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.firstAlphabet(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends