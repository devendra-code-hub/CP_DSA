class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int>mp;
         
        int ans=0, l=0;
        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            while(l<n && mp[nums[r]] >k){
                 mp[nums[l]]--;
                l++;
            }

            int len = r-l+1;
            ans=max(ans, len);
        }

        return ans;
    }
};