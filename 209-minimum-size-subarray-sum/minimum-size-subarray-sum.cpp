class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
         int ans=INT_MAX;
       int left=0,sum=0;
      

       for(int right=0; right<n; ++right){
             sum+=nums[right];
        while(sum>=target ){
            int len = right-left+1;
            ans = min(ans, len);
            sum -=nums[left];
            left++;
        
        }

       } 
       
       return ans == INT_MAX ? 0 : ans;
    }
};