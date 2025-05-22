class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n=nums.size();

     // Kadane's Algo
     int sum_i=nums[0];
     int res=nums[0];
     for(int i=1; i<n; ++i){

        sum_i=max(sum_i + nums[i], nums[i]);
        
        res=max(res,sum_i);
     }
     return res;
        
    }
};