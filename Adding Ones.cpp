//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Prefix sum approach is used in this problem

Updates = {1,1,2,3}     ... 1 based indexing
a[] = {0,0,0}

for updates[0] => 1 
    a[] = {1,0,0}
for updates[1] => 1 
    a[] = {2,0,0}
for updates[2] => 2 
    a[] = {2,1,0}
for updates[3] => 3 
    a[] = {2,1,1}

after second for loop,
a[] = {2,3,4}
*/

class Solution
{
public:
    void update(int a[], int n, int updates[], int k)
    {
        for (int i = 0; i < k; i++)
        {
            a[updates[i] - 1]++;
        }
        for (int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n] = {0}, updates[k] = {0};
        for (int i = 0; i < k; i++)
            cin >> updates[i];
        Solution ob;
        ob.update(a, n, updates, k);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends