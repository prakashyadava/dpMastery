//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int findMin(int arr[],int i,int calSum,int sumTotal,vector<vector<int>>&dp){
        if(i==0){
            return abs(sumTotal-2*calSum);
        }
        if(dp[i][calSum]!=-1)
        return dp[i][calSum];
        return dp[i][calSum] = min(findMin(arr,i-1,calSum+arr[i],sumTotal,dp),findMin(arr,i-1,calSum,sumTotal,dp));
    }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sumTotal = 0;
	    
	    for(int i=0;i<n;i++){
	        sumTotal += arr[i];
	    }
	    vector<vector<int>>dp(n+1,vector<int>(sumTotal+1,-1));
	    return findMin(arr,n-1,0,sumTotal,dp);
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
