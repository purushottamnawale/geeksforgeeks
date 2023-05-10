//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            String a[] = in.readLine().trim().split("\\s+");
            String keys[] = new String[n];
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                keys[i] = a[2 * i];
                arr[i] = Integer.parseInt(a[2 * i + 1]);
            }
            String s = in.readLine();

            Solution ob = new Solution();
            System.out.println(ob.map(n, keys, arr, s));
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    static int map(int n, String keys[], int arr[], String s) {
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (s.equals(keys[i])) {
                ans = i;
            }
        }
        return ans == -1 ? -1 : arr[ans];
    }
}