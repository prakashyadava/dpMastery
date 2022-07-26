//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int check(int N,int arr[],int i,vector<vector<int>>&dp,int sum){
        if(i>N-1 || sum<0){
            return 0 ;
        }
        if(sum==0){
            return 1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(arr[i]<=sum){
            return dp[i][sum] = check(N,arr,i+1,dp,sum-arr[i]) || check(N,arr,i+1,dp,sum);
        }
        return dp[i][sum] = check(N,arr,i+1,dp,sum);
        
        
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int x=0;x<N;x++){
            sum += arr[x];
        }
        if(sum%2!=0){
            return 0;
        }
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        return check(N,arr,0,dp,sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
