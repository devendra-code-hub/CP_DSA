class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(), sum=0, ans=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            if(f.find(sum-goal)!= f.end())
          ans+=f[sum-goal];
          f[sum]++;
        }

        return ans;
    }
};