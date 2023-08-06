//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Max Circular Subarray Sum:

Input:
1 7
8 -8 9 -9 10 -11 12

Output:
22
*/
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int normalMaxSum(int arr[], int num)
    {
        int cur_max = arr[0];
        int max_sum = arr[0];
        for (int i = 1; i < num; i++)
        {
            cur_max = max(arr[i], cur_max + arr[i]);
            max_sum = max(cur_max, max_sum);
        }
        return max_sum;
    }
    int circularSubarraySum(int arr[], int num)
    {

        int nor_sum = normalMaxSum(arr, num);
        if (nor_sum < 0)
        {
            return nor_sum;
        }
        int arr_sum = 0;
        for (int i = 0; i < num; i++)
        {
            arr_sum += arr[i];
            arr[i] = -arr[i];
        }
        int max_cir_sum = arr_sum + normalMaxSum(arr, num);
        return max(nor_sum, max_cir_sum);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;

    // testcases
    cin >> T;

    while (T--)
    {
        int num;

        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
}
// } Driver Code Ends