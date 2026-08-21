class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
           unordered_map<int, int>mp;
         vector<int>ans;
         for(auto c: nums) mp[c]++;
         for(auto it : mp){
            if(it.second>floor(nums.size()/3.0)) ans.push_back(it.first);
         }
         return ans;
    
    }
};