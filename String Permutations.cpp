//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
String Permutations:

Input:
1 ABC

Ouput:
ABC ACB BAC BCA CAB CBA

Explanation:

permutations(ABC,0)
    permutations(ABC,1)
        permutations(ABC,2)
            push ABC
        permutations(ACB,2)
            push ACB
    permutations(BAC,1)
        permutations(BAC,2)
            push BAC
        permutations(BCA,2)
            push BCA
    permutations(CBA,1)
        permutations(CBA,1)
            push CBA
        permutations(CAB,2)
            push CAB
            
*/
class Solution
{
public:
    void permutations(string str, int i, int n, vector<string> &v)
    {
        if (i == n - 1) // base condition
        {
            v.push_back(str);
            return;
        }

        // process each character of the remaining string
        for (int j = i; j < n; j++)
        {
            swap(str[i], str[j]); // swap character at index i with current character

            permutations(str, i + 1, n, v); // recurse for string [i+1, n]

            swap(str[i], str[j]); // backtracking: Optional (restore the string to its original state)
            
        }
    }

    vector<string> permutation(string S)
    {
        vector<string> v;
        permutations(S, 0, S.length(), v);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for (string s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends