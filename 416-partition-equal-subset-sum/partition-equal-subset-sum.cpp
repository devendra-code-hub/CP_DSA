class Solution {
public:
int f(int i, int sum, int n, int ts, vector<int>&nums, vector<vector<int>>&dp){
    if(sum == (ts-sum)) return 1;
    if(sum>(ts-sum) || i>=n) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    int t= f(i+1, sum+nums[i], n, ts, nums, dp);
    int nt= f(i+1, sum, n, ts, nums, dp);

    return dp[i][sum]= t || nt;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int ts=accumulate(nums.begin(), nums.end(),0);
        vector<vector<int>>dp(n, vector<int>(ts,-1));

        return f(0,0,n,ts,nums,dp);
    }
};