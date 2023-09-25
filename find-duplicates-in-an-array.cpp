//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Find duplicates in an array

Input:
1
5
2 3 1 2 3

Output:
2 3

Explanation:
n = 5
arr = [2, 3, 1, 2, 3]

for i = 0
    index = arr[0]
    index = 2
    arr[2] = 1 + 5
    arr[2] = 6

    i = 1
    index = arr[1]
    index = 3
    arr[3] = 2 + 5
    arr[3] = 7

    i = 2
    index = arr[2]
    index = 1
    arr[1] = 3 + 5
    arr[1] = 8

    i = 3
    index = arr[3]
    index = 2
    arr[2] = 6 + 5
    arr[2] = 11

    i = 4
    index = arr[4]
    index = 3
    arr[3] = 7 + 5
    arr[3] = 12


Before:
arr = [2, 3, 1, 2, 3] 

After:
arr = [2, 8, 11, 12, 3]


for i = 0
    if (arr[0] / 5) > 1 => 2 / 5 > 1 => 0 > 1 => false

    i = 1
    if (arr[1] / 5) > 1 => 8 / 5 > 1 => 1 > 1 => false

    i = 2
    if (arr[2] / 5) > 1 => 11 / 5 > 1 => 2 > 1 => true => ans.push_back(2) => ans = [2]

    i = 3
    if (arr[3] / 5) > 1 => 12 / 5 > 1 => 2 > 1 => true => ans.push_back(3) => ans = [2, 3]

    i = 4
    if (arr[4] / 5) > 1 => 3 / 5 > 1 => 0 > 1 => false
    
*/

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    vector<int> duplicates(int arr[], int n)
    {
        // First check all the values that are present in an array.
        // Then go to that values as indexes and increment by the size of array.
        for (int i = 0; i < n; i++)
        {
            int index = arr[i] % n;
            arr[index] += n;
        }        

        // Now check which value exists more than once by dividing with the size of array
        bool flag = false;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] / n) > 1)
            {
                ans.push_back(i);
                flag = true;
            }
        }
        if (!flag)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends