//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int maxProfit(int price[],int n,int i,vector<vector<int>>&dp){
      if(i>n-1 || n==0){
          return 0;
      }
      if(dp[i][n]!=-1){
          return dp[i][n];
      }
      return dp[i][n]=max(price[i]+maxProfit(price,n-i-1,i,dp),maxProfit(price,n,i+1,dp));
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return maxProfit(price,n,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
