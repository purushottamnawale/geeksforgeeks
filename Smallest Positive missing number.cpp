//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        int shift = separator(arr, n); // Function to separate positive and negative numbers.
        return findMissingPositive(arr + shift, n - shift); // Shifting the array to access only positive part.
    }
    int separator(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j;
    }
    int findMissingPositive(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int correctIndex = abs(arr[i]) - 1; // 1 is subtracted because indexing starts from 0
            if (correctIndex < n && arr[correctIndex] > 0)
            {
                arr[correctIndex] = -arr[correctIndex]; // Marking indices of all positive numbers which are present as negative
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                return i + 1; //  1 is added because indexing starts from 0.
            }
        }
        return n + 1;
    }
};

/*
int missingNumber(int arr[], int n)
{
    int check[n + 1];
    for (int i = 1; i <= n; i++)
    {
        check[i] = false;
    }
    int sum = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            check[arr[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i] == false)
        {
            return i;
        }
    }
    return -1;
}
*/

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends