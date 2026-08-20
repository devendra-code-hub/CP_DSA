class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        int c1=0,c2=0;
        for(int i=2;i<nums.size(); i++){
            if(a1.back() > a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        vector<int>ans;
        for(auto n : a1) ans.push_back(n);
        for(auto n : a2) ans.push_back(n);

        return ans;
    }
};