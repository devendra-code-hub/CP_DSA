class Solution {
public:
  int m=1e9+7;
    int f(int idx, int g1, int g2, vector<vector<vector<int>>>&dp, vector<int>&nums){
        if(idx == nums.size()){
            if(g1 == g2 && g1>0) return 1;
            return 0;
        }
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];
        int way=0;
        way=(way+f(idx+1,g1,g2,dp,nums))%m;
        way=(way+f(idx+1,gcd(g1,nums[idx]),g2,dp,nums))%m;
        way=(way+f(idx+1,g1,gcd(g2,nums[idx]),dp,nums))%m;

        return dp[idx][g1][g2]=way;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int mx_val=*max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(mx_val+1,vector<int>(mx_val+1,-1)));
     return  f(0,0,0,dp,nums);
       
    }
};