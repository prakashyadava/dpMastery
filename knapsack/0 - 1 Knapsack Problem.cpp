//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int maxProfit(int W,int wt[],int val[],int n , int i,vector<vector<int>>&dp){
        if(i>n-1 || W==0){
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        if(wt[i]<=W){
            return dp[i][W] = max(val[i]+maxProfit(W-wt[i],wt,val,n,i+1,dp),maxProfit(W,wt,val,n,i+1,dp));
            
        }
        return dp[i][W] = maxProfit(W,wt,val,n,i+1,dp);
        
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return maxProfit(W,wt,val,n,0,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
