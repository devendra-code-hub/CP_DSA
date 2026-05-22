class Solution {
    private :
       bool f(int idx, int s, int sum, int n, vector<int>&nums, vector<vector<int>>&v){
        if(s==sum-s) return true;
        if(idx>=n || s>sum-s) return false;
        if(v[idx][s] !=-1) return v[idx][s];
        bool l= f(idx+1, s+nums[idx],sum, n,nums,v);
        bool r= f(idx+1, s,sum, n,nums,v);

        return v[idx][s]=l||r;
       }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>v(n,vector<int>(sum,-1));

        return f(0,0,sum,n,nums,v);

    }
};