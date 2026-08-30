class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+2,0);
        vector<int>dp2(n+2,0);
        for(int i=n-1; i>=1; i--){
            int t=nums[i]+dp1[i+2];
            int nt=dp1[i+1];
            dp1[i]=max(t, nt);
        }
        for(int i=n-2; i>=0; i--){
            int t=nums[i]+dp2[i+2];
            int nt=dp2[i+1];
            dp2[i]=max(t, nt);
        }

        return max(dp1[1], dp2[0]);
    }
};