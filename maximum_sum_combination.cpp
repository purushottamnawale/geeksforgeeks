//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Maximum Sum Combination


Input:
1
2
2
3 2
1 4


Output:
7 6

Input:
1
4
3
1 4 2 3
2 5 1 6

Output:
10 9 9

A = [1 4 2 3]
B = [2 5 1 6]

Sort A & B

A = [1 2 3 4]
B = [1 2 5 6]

pq = pair[0] = first  = 10
               second = first  = 3
                        second = 3

my_set = pair[0] = first  = 3
                   second = 3


for count = 0
    temp = first  = 10
           second = first  = 3
                    second = 3

    pq = []

    ans = [10]

    i = 3
    j = 3

    if 2 >= 0:
        sum = 3 + 6 = 9 

        temp1 = first = 2
                second = 3
        
        if temp1 is unique:
            pq = first  = 9
                 second = first = 2
                          second = 3
            
            my_set = pair[0] = first  = 2
                               second = 3
                     pair[1] = first  = 3
                               second = 3
            
    if 2 >= 0:
        sum = 4 + 5 = 9

        temp1 = first = 3
                second = 2

        if temp1 is unique:
            pq = first  = 8
                 second = first = 2
                          second = 2

            pq = pair[0] = first  = 9
                           second = first  = 3
                                    second = 2
                 pair[1] = first  = 9
                           second = first  = 2
                                    second = 3
            
            my_set = pair[0] = first  = 2
                               second = 3
                     pair[1] = first  = 3
                               second = 2
                     pair[2] = first  = 3
                             = second = 3
            
    
    count = 1
    temp = first  = 9
           second = first  = 3
                    second = 2

    pq = pair[0] = first  = 9
                   second = first  = 2
                            second = 3
    ans = [10 9]

    i = 3
    j = 2

    if 2 >= 0:
        sum = 4 + 2 = 8

        temp1 = first = 2
                second = 2

        if temp1 is unique:
            pq = pair[0] = first  = 9
                           second = first  = 2
                                    second = 3
                 pair[1] = first  = 8
                           second = first  = 2
                                    second = 2
                 pair[2] = first  = 6
                           second = first  = 3
                                    second = 1
            
            my_set = pair[0] = first  = 2
                               second = 2
                     pair[1] = first  = 2
                               second = 3
                     pair[2] = first  = 3
                               second = 1
                     pair[3] = first  = 3
                               second = 2
                     pair[4] = first  = 3
                             = second = 3
    if 1 >= 0:
        sum = 3 + 5 = 6

        temp1 = first = 3
                second = 1

        if temp1 is unique:
            pq = pair[0] = first  = 9
                           second = first  = 2
                                    second = 3
                 pair[1] = first  = 8
                           second = first  = 2
                                    second = 2
            
            my_set = pair[0] = first  = 2
                               second = 2
                     pair[1] = first  = 2
                               second = 3
                     pair[2] = first  = 3
                               second = 2
                     pair[3] = first  = 3
                             = second = 3
    
    count = 2
    pq = pair[0] = first  = 8
                   second = first  = 2
                            second = 2
            pair[1] = first  = 6
                      second = first  = 3
                               second = 1
    ans = [10, 9, 9]
    i = 2
    j = 3

    if 2 >= 0:
        sum = 3 + 5 = 8

        temp1 = first  = 2
                second = 2

        if temp1 is unique:

    






*/

class Solution
{
public:
    // vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    // {
    //     priority_queue<pair<int, pair<int, int>>> pq;
    //     sort(A.begin(), A.end());
    //     sort(B.begin(), B.end());
    //     for (int i = 0; i < N; i++)
    //     {
    //         pq.push({A[i] + B[N - 1], {i, N - 1}});
    //     }
    //     vector<int> ans;
    //     while (!pq.empty() && K--)
    //     {
    //         auto it = pq.top();
    //         pq.pop();
    //         int data = it.first;
    //         int x = it.second.first;
    //         int y = it.second.second;
    //         ans.push_back(data);
    //         if (y != 0)
    //         {
    //             pq.push({A[x] + B[y - 1], {x, y - 1}});
    //         }
    //     }
    //     return ans;
    // }

    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // sorting both arrays in ascending order.
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> ans;

        // Creating a priority queue to store maximum sums of combinations.
        priority_queue<pair<int, pair<int, int>>> pq;

        // Creating a set to store visited combinations.
        set<pair<int, int>> my_set;

        // Pushing the maximum sum of combinations obtained from last elements
        // of both arrays along with their indices.
        pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N - 1, N - 1)));

        // inserting the indices of last elements in set.
        my_set.insert(make_pair(N - 1, N - 1));

        // iterating K times to find K maximum sum combinations.
        for (int count = 0; count < K; count++)
        {
            // popping the maximum sum from priority queue.
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();

            // storing the maximum sum in the answer array.
            ans.push_back(temp.first);

            // getting the indices of the elements used to get the maximum sum.
            int i = temp.second.first;
            int j = temp.second.second;

            // checking if it is possible to consider the next element
            // from A array and calculating the sum.
            if (i - 1 >= 0)
            {
                int sum = A[i - 1] + B[j];

                // creating a pair to store the indices.
                pair<int, int> temp1 = make_pair(i - 1, j);

                // checking if the pair already exists in the set.
                if (my_set.find(temp1) == my_set.end())
                {
                    // if not, pushing the sum and indices to priority queue
                    // and inserting the indices in set.
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }

            // checking if it is possible to consider the next element
            // from B array and calculating the sum.
            if (j - 1 >= 0)
            {
                int sum = A[i] + B[j - 1];

                // creating a pair to store the indices.
                pair<int, int> temp1 = make_pair(i, j - 1);

                // checking if the pair already exists in the set.
                if (my_set.find(temp1) == my_set.end())
                {
                    // if not, pushing the sum and indices to priority queue
                    // and inserting the indices in set.
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }
        }

        // returning the answer array containing the maximum sum combinations.
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends