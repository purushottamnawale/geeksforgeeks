//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++

/*
Seaching a number

int search(int arr[], int n, int k)
{
    int *foundElement = std::find(arr, arr + n, k);
    int index = foundElement - arr;
    return index < n ? ++index : -1;
}

Explanation:

1. find(arr, arr + n, k): This part uses the find function to search for the value k in the range defined by arr and 
    arr + n. The find function returns an iterator pointing to the first occurrence of k in the range, or it returns 
    arr + n if k is not found.
2. find(arr, arr + n, k) - arr: This part subtracts the starting iterator arr from the iterator returned by find. 
    This subtraction operation yields the index of the found element relative to the start of the array.
3. int i{...}: This part declares a new integer variable i and initializes it with the result of the subtraction.
*/

class Solution
{
public:
    int search(int arr[], int n, int k)
    {
        int i{find(arr, arr + n, k) - arr};
        return i < n ? ++i : -1;
    }
};

/*
Alternate Solution:
int search(int arr[], int n, int k) {
    for(int i=0; i<n; i++)
        if(arr[i] == k)
            return i+1;
    return -1;
}

*/

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n >> k;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.search(a, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends