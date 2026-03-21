class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0; i<n; i++)if(nums[i]%2==0)mp[nums[i]]++;
        for(auto it: nums){
            if(it%2==0 && mp[it]==1) return it;
        }

        return -1;
    }
};