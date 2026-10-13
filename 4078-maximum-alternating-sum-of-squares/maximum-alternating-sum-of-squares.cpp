class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        for(auto it : nums) v.push_back(abs(it));
        sort(v.rbegin(), v.rend());
        long long ans=0;
        int i=0;
        for(; i<(n+1)/2; i++) ans+=(v[i]*v[i]);
        for(; i<n; i++) ans-=(v[i]*v[i]);

        return ans;
    }
};