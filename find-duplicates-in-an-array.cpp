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
2 3 1 2 3

index = 2
arr[2] = 1
arr[2] = 6

index = 3
arr[3] = 2
arr[3] = 7

index = 1
arr[1] = 3
arr[1] = 8

index = 2
arr[2] = 6
arr[2] = 11

index = 3
arr[3] = 7
arr[3] = 12

*/

class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        // First check all the values that are present in an array
        // Then go to that values as indexes and increment by the size of array
        for (int i = 0; i < n; i++)
        {
            int index = arr[i] % n;
            // cout<<arr[index]<<n<<arr[index]+n<<endl;
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
            ans.push_back(-1);
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