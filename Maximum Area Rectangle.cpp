//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int calculate_Area(vector<pair<int, int>> &rect, int N)
    {
        int area, maxArea = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            area = rect[i].first * rect[i].second;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> rect;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            rect.push_back({a, b});
        }
        Solution ob;
        cout << ob.calculate_Area(rect, n) << endl;
    } //{ Driver Code Starts
#include <bits/stdc++.h>
    using namespace std;

    // } Driver Code Ends
    class Solution
    {
    public:
        int calculate_Area(vector<pair<int, int>> &rect, int N)
        {
            int area, maxArea = INT_MIN;
            for (int i = 0; i < N; i++)
            {
                area = rect[i].first * rect[i].second;
                maxArea = max(maxArea, area);
            }
            return maxArea;
        }
    };

    //{ Driver Code Starts.
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            vector<pair<int, int>> rect;
            for (int i = 0; i < n; i++)
            {
                int a, b;
                cin >> a >> b;
                rect.push_back({a, b});
            }
            Solution ob;
            cout << ob.calculate_Area(rect, n) << endl;
        }
        return 0;
    }

    // } Driver Code Ends
    return 0;
}

// } Driver Code Ends