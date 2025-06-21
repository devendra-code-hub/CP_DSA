class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix_p(n),suffix_p(n);
        prefix_p[0]=nums[0];
        suffix_p[n-1]=nums[n-1];
        for(int i=1; i<n; ++i){
            prefix_p[i]=prefix_p[i-1]*nums[i];
        }
        for(int i=n-2; i>=0; --i){
            suffix_p[i]=suffix_p[i+1]*nums[i];
        }
        nums[0] = suffix_p[1];
        nums[n-1] = prefix_p[n-2];
        for(int i=1; i<n-1; ++i){
            nums[i] = prefix_p[i-1]*suffix_p[i+1];
        }
        

        return nums;
    }
};