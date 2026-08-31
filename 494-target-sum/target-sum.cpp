class Solution {
public:
using ll=long long;
int f(int i, int sum, int n, int target, vector<int>&nums, vector<vector<int>>&dp){
   if(i==n){
         if(sum == (target+1e3)) return 1;
         return 0;
   }
    
    if(i>=n) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    int add= f(i+1, sum+nums[i], n, target, nums, dp);
    int sub= f(i+1, sum-nums[i], n, target, nums, dp);

    return dp[i][sum]=add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(2001,-1));
        return f(0, 1e3,n,target, nums, dp);
    }
};