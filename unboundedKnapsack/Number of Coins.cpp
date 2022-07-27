//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCal(int coins[],int M,int V,int i,vector<vector<int>>&dp){
	    if(i==M){
	        if(V==0){
	            return 0;
	        }
	        return 1e7;
	        
	    }
	    if(dp[i][V]!=-1)
	        return dp[i][V];
	    if(coins[i]<=V){
	        return dp[i][V] =min(1+minCal(coins,M,V-coins[i],i,dp),minCal(coins,M,V,i+1,dp));
	    }
	    return dp[i][V]=minCal(coins,M,V,i+1,dp);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans = minCal(coins,M,V,0,dp);
	    if(ans==1e7)
	    return -1;
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
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
