class Solution {
public:
int f(int sum, int n, vector<int>&dp){
    if(sum==n) return 1;
    if(sum>n) return 0;
    if(dp[sum] != -1) return dp[sum];
    int s1=f(sum+1, n, dp);
    int s2=f(sum+2, n, dp);
    return dp[sum]=s1+s2;
}
    int climbStairs(int n) {
        // vector<int>dp(n,-1);
        // return f(0,n,dp);
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1; i>=0; i--){
            if(i+2<=n)dp[i]+=dp[i+2];
            dp[i]+=dp[i+1];
        }
        return dp[0];
    }
};