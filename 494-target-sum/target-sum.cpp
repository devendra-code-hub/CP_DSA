class Solution {
public:
using ll =long long;
int f(int idx, int sum, int n, int target, vector<int>&nums, vector<vector<int>>&dp){
   if(idx == n){
    if(sum == target) return 1;
    return 0;
    }
    // if(idx>=n) return 0;
    if(dp[idx][sum +1000] != -1) return dp[idx][sum+1000];
    int a=f(idx+1, sum+nums[idx], n, target, nums, dp);
    int s=f(idx+1, sum-nums[idx], n, target, nums, dp);

    return dp[idx][sum+1000]=a+s;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(2001,-1));
        f(0,0,n,target,nums,dp);
        return dp[0][0+1000];
    }
};