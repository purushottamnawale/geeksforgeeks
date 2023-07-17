//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
First non-repeating character in a stream:

Rules:
1. Push a character that has appeared only once in the stream up to that point.
2. If there are multiple characters that have appeared only once, push the one that was the first to appear among them.
3. If there are no characters that have appeared only once, push the character '#'.

Example 1:

Input:
1 abcbbac

Output:
aaaaac#

1.
a b c b b a c
|
ans = a, as it is the first character that has appeared only once.

2.
a b c b b a c
  |
ans = aa, as a is the first character that has appeared only once.

3.
a b c b b a c
    |
ans = aaa

4.
a b c b b a c
      |
ans = aaaa, b will be removed from the queue as it has appeared more than once.

5.
a b c b b a c
        |
ans = aaaaa

6.
a b c b b a c
          |
ans = aaaaac, a will be removed from the queue as it has appeared more than once. c will be pushed into the queue as it has appeared only once.

7.
a b c b b a c
            |
ans = aaaaac#, # will be pushed into the answer as there are no characters that have appeared only once.

Example 2:

Input:
1 aabc

Output:
a#bb

*/
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        int freq[26] = {0};
        queue<char> que; // Queue to store the characters that have appeared only once
        string ans = "";
        for (int i = 0; i < A.length(); i++)
        {
            freq[A[i] - 'a']++;
            if (freq[A[i] - 'a'] == 1) // Push only the characters that have appeared only once
            {
                que.push(A[i]);
            }
            while (que.empty() == false && freq[que.front() - 'a'] > 1) // Remove the que.front() characters that have appeared more than once
            {
                que.pop();
            }
            if (que.empty()) // If there are no characters that have appeared only once, push #
            {
                ans += "#";
            }
            else
            {
                ans += que.front(); // First non-repeating character
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends