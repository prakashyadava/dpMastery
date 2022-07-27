// https://practice.geeksforgeeks.org/problems/coin-change2448/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int find(int S[],int m,int n,int i,vector<vector<long long int>>&dp){
      if(n==0)
      return 1;
      if(i>m-1|| n<0){
          return 0;
      }
      if(dp[i][n]!=-1){
          return dp[i][n];
      }
      if(S[i]<=n)
        return dp[i][n]=find(S,m,n-S[i],i,dp) + find(S,m,n,i+1,dp);
        return dp[i][n]=find(S,m,n,i+1,dp);
  }
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,-1));
        return find(S,m,n,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}
// } Driver Code Ends
