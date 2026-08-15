class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool ch_zero = true;
        int ans=nums[0];
        for(int i=1; i<n; i++){
             ans^=nums[i];
        }
        int cnt0=0;
        for(auto num : nums) if(num ==0) cnt0++;
        if(cnt0==n) return 0;
        if(ans==0) return n-1;

        return n;
    }
};