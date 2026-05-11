class Solution {
public:
    void digit(int n, vector<int>&ans){
        vector<int>rev;
        while(n){
            rev.push_back(n%10);
            n=n/10;
        }
        reverse(rev.begin(), rev.end());

        for(auto r: rev){
            ans.push_back(r);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            digit(nums[i],ans);
        }
        return ans;
    }
};