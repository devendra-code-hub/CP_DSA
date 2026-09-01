class Solution {
public:
void f(  int i,vector<int>v, vector<int>&nums, set<vector<int>>&s){
    if(i>=nums.size()){
        s.insert(v);
        return;
    }
    
    v.push_back(nums[i]);
    f(i+1, v, nums, s);
    v.pop_back();
    f(i+1, v, nums, s);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>v;
        f(0,v, nums, s);
        vector<vector<int>>ans;
        for(auto it : s){
            ans.push_back(it);
        }

        return ans;
    }
};