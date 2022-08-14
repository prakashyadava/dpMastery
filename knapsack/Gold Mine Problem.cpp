
//https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 int helper(vector<vector<int>>&arr,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i<0 || i==n || j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right_up = helper(arr,i-1,j+1,n,m,dp);
    int right = helper(arr,i,j+1,n,m,dp);
    int right_down = helper(arr,i+1,j+1,n,m,dp);
    return dp[i][j] = arr[i][j] + max(right_down,max(right,right_up));
    }
public:

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int mx = INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++){
        mx = max(mx,helper(M,i,0,n,m,dp));
    }
    return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
