//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
If we take a close look then we observe a pattern.
Let’s take an example:

arr[] = [1, 2, 3], n = 3
All subarrays :  [1], [1, 2], [1, 2, 3], [2], [2, 3], [3]

here first element ‘arr[0]’ appears 3 times
second element ‘arr[1]’ appears 4 times
third element ‘arr[2]’ appears 3 times

Every element arr[i] appears in two types of subsets:

i)  In subarrays beginning with arr[i]. There are
	(n-i) such subsets. For example [2] appears
	in [2] and [2, 3].

ii) In (n-i)*i subarrays where this element is not
	first element. For example [2] appears in [1, 2] and [1, 2, 3].

Total of above (i) and (ii) = (n-i) + (n-i)*i  = (n-i)(i+1)

For arr[] = {1, 2, 3}, sum of subarrays is:

For i=0
arr[0] * (0 + 1) * (3 - 0) = 1 * 1 * 3 = 1 * 3 = 3

For i=1
arr[1] * (1 + 1) * (3 - 1) = 2 * 2 * 2 = 2 * 4 = 8

For i=2
arr[2] * (2 + 1) * (3 - 2) = 3 * 3 * 1 = 3 * 3 = 9

Total = 3 + 8 + 9 = 20

*/

// User function template for C++

class Solution
{
public:
	long long subarraySum(long long a[], long long n)
	{
		long long int sum = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; i++)
		{
			sum += (a[i] * (i + 1) * (n - i)) % mod;
		}
		return sum % mod;
	}
};

//{ Driver Code Starts.
int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long a[n + 5];
		for (long long i = 0; i < n; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.subarraySum(a, n) << endl;
	}
	return 0;
}

// } Driver Code Ends