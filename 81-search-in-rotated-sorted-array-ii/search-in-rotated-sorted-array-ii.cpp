class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        auto it=find(nums.begin(),nums.end(),target) ;
        if(it !=nums.end()) return true;

        return false;
    }
};