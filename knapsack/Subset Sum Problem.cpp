//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution{   
    int isSum(vector<int>arr,int i,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }if(i>=arr.size()){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(arr[i]<=sum)
        return dp[i][sum] = isSum(arr,i+1,sum-arr[i],dp) || isSum(arr,i+1,sum,dp);
        
        return dp[i][sum]=isSum(arr,i+1,sum,dp);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return isSum(arr,0,sum,dp);
    }
};
