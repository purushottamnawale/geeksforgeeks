//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;

public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if (i < 0 || i >= (int)chocolates.size() || countOfCalls > 50)
            return -1;
        return chocolates[i];
    }
};

// } Driver Code Ends
// User function Template for Java

/*
Instructions -

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution
{
public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    // Return the number of chocolates Geek had enjoyed out of 'n' chocolates availabe in the 'shop'.
    // An unordered_map is like a data structure of dictionary type that stores elements in itself. It contains successive pairs (key, value), which allows fast retrieval of an individual element based on its unique key.
    long long find(int n, long k)
    {
        long long ans = 0;
        unordered_map<int, int> hash;
        int mid = n;
        while (1)
        {
            int low = 0, high = mid - 1;
            // we are setting high to mid-1 because in last search, we have got the desired chocolate and we have already included maximum instances of it, so there's no way that we'll ever be able to buy it again.

            int cost = -1;
            while (low <= high)
            {
                mid = (low + high) / 2;

                // If the cost of the chocolate has already been calculated and stored in the hash map, the algorithm can retrieve it in constant time, which is faster than calling the shop.get() function again.
                int curCost;
                if (hash.count(mid))
                {
                    curCost = hash[mid];
                }
                else
                {
                    curCost = shop.get(mid);
                    hash[mid] = curCost;
                }
                if (curCost > cost && curCost <= k) // desired chocolate found
                {
                    cost = curCost;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }

            if (cost == -1 || cost > k) // the remaining cost k isn't enough to buy any chocolate so break
                break;

            ans += k / cost; // take all instances of the selected chocolate
            k %= cost;       // reduce the remaining cost
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);
        long long k;
        cin >> k;

        Shop shop;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }

        Solution obj(shop);
        long long res = obj.find(n, k);

        cout << res << endl;
    }
}

// } Driver Code Ends