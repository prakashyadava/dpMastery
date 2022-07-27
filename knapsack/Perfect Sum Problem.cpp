//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9 + 7;
    int ans(int arr[],int n,int sum, int i,vector<vector<int>>&dp){
        if(i==n){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        if(arr[i]<=sum){
            return dp[i][sum]=ans(arr,n,sum-arr[i],i+1,dp)%mod + ans(arr,n,sum,i+1,dp)%mod;
        }
        return dp[i][sum]=ans(arr,n,sum,i+1,dp)%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return ans(arr,n,sum,0,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
