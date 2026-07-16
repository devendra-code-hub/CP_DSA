class Solution {
public:
using ll=long long;
    int f(int idx, ll sum, int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(sum==amount) return 0;
        if(sum>amount || idx>=n) return 1e9;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int nt = f(idx+1,sum,n,amount,coins, dp);
       int t =1+ f(idx,sum+coins[idx],n,amount,coins, dp);
        return dp[idx][sum] = min(nt,t);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
         if(amount==0) return 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        f(0,ll(0),n,amount,coins,dp);
        return dp[0][0]==1e9? -1: dp[0][0];

    }
};