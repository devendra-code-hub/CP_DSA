class Solution {
public:
int f(int idx, int sum, int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
    if(sum== amount) return 1;
    if(sum> amount || idx>=n) return 0;
    if(dp[idx][sum] !=-1 ) return dp[idx][sum];
    int t=f(idx, sum+coins[idx], n, amount, coins, dp);
    int nt=f(idx+1, sum, n, amount, coins, dp);

    return dp[idx][sum]=t+nt;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0) return 1;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        f(0,0,n,amount,coins,dp);
        return dp[0][0]==-1 ? 0: dp[0][0];
    }
};