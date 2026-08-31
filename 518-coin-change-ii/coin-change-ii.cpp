class Solution {
public:
int f(int i, int sum, int n, int amt, vector<int>&coins, vector<vector<int>>&dp){
    if(sum==amt) return 1;
    if(sum>amt || i>=n) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    int t=f(i, sum+coins[i], n, amt, coins, dp);
    int nt=f(i+1, sum, n, amt, coins, dp);

    return dp[i][sum]=t+nt;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount,-1));
        return f(0,0,n, amount, coins, dp);
    }
};