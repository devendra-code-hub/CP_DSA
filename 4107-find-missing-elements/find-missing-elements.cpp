class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        vector<int>v(101,0);
        for(auto c: nums) v[c]=1;
        int mx=*max_element(nums.begin(), nums.end());
        int mn=*min_element(nums.begin(), nums.end());
        for(int i=1+mn; i<mx; i++){
            if(v[i]==0) ans.push_back(i);
        }
        
        return ans;
    }
};