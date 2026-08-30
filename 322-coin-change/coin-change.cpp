class Solution {
public:
using ll=long long;
int f(int i, ll sum, int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
    if(sum==amount) return 0;
    if(sum>amount || i>=n) return 1e9;
    if(dp[i][sum] != -1) return dp[i][sum];
    int t=1+f(i, sum+(ll)coins[i], n, amount, coins, dp);
    int nt=f(i+1, sum, n, amount, coins, dp);

    return dp[i][sum] = min(t, nt);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount,-1));
        return f(0,0,n,amount,coins,dp)==1e9 ? -1: f(0,0,n,amount,coins,dp);
    }
};