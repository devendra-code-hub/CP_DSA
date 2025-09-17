class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int c = n/3;
        vector<int>ans;
        for(auto it : freq){
            if(it.second > c){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};