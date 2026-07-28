class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);

         int mx=1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i]>nums[prev]){
                    if(1+ dp[prev] > dp[i]){
                        dp[i]=dp[prev] +1;
                        count[i]=count[prev];
                    }
                    else if(1+ dp[prev] == dp[i]){
                        count[i]+=count[prev];
                    }
                }
                
            }
             mx=max(mx, dp[i]);
        }
        int ans=0;
            for(int i=0; i<n; i++){
                if(dp[i] == mx){
                    ans+=count[i];
                }
            }

            return ans;
    }
};