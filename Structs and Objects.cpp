//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    Rectangle() {}
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
};
int area(Rectangle r);
void maxArea(Rectangle arr[], int n);

// } Driver Code Ends
// User function Template for C++

int area(Rectangle r)
{
    int l = r.length;
    int b = r.breadth;
    return l * b;
}

void maxArea(Rectangle arr[], int n)
{
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, area(arr[i]));
    }
    cout << maxA;
    cout << endl;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;         // Number of rectangle objects
        Rectangle arr[n]; // array of rectangle objects
        for (int i = 0; i < n; i++)
        {
            int l, b;
            cin >> l >> b;     // length and breadth of a object
            Rectangle r(l, b); // creating a object r
            arr[i] = r;        // fill the array
        }
        maxArea(arr, n); // function to calculate maxArea
    }
    return 0;
}

// } Driver Code Ends