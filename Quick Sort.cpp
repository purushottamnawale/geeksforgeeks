//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
 public:
    void quickSort(int a[], int low, int high){
        if(low >= high)
            return;
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
    
    public:
    int partition (int a[], int low, int high){
     //index j is the last point (inclusive) upto which all elements are <= pivot 
        int j = low - 1, pivot = a[high];
        for(int i = low; i <= high - 1; i++){
            if(a[i] <= pivot){
                j++;
                swap(a[i], a[j]);
            }
        }
        swap(a[j + 1], a[high]);
        return j + 1;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends