class Solution {
public:
    int f(int idx, int prevIdx, vector<int>&nums, vector<vector<int>>& dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

        int len= f(idx+1, prevIdx, nums, dp);
        if(prevIdx == -1 || nums[idx]%nums[prevIdx]==0){
            len=max(len, 1+ f(idx+1, idx, nums, dp));
        }

        return dp[idx][prevIdx+1] = len;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        sort(nums.begin(), nums.end());
        f(0,-1,nums, dp);

        int idx=0,prevIdx=-1;
        vector<int>ans;
        while(idx<n){

            if(prevIdx == -1 || nums[idx]%nums[prevIdx] == 0){

                int t= 1+f(idx+1, idx, nums, dp);
                int nt = f(idx+1, prevIdx, nums, dp);

                if(t>=nt){
                    ans.push_back(nums[idx]);
                    prevIdx=idx;
                }
            }

            idx++;
        }

        return ans;
    }
};