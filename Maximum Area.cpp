//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Area of Triangle = 1/2 * Base * Height

The area of a right-angled triangle of the given hypotenuse is maximum when the triangle is isosceles.
i.e. Base = Height

Area = 1/2 * Base * Height
2.Area = Base*Height
2.Area = Base^2                         1)


By Pythagoras theorem, we know that
Hypotenuse^2 = Base^2 + Height^2

Hypotenuse^2 = 2.Base^2                2)

From 1) and 2)
Hypotenuse^2 = 2.Area
Hypotenuse = sqrt(2.Area)

return 2 * sqrt(N);
*/
class Solution
{
public:
    int getHypotenuse(long long N)
    {
        return 2 * sqrt(N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.getHypotenuse(N) << endl;
    }
    return 0;
}
// } Driver Code Ends