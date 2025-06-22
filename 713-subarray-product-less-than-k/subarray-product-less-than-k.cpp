class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k <= 1) return 0; 
        int n = nums.size(), cnt=0,left=0,p=1;
        
        for(int right=0; right<n; right++ ){
            p*=nums[right];
            while(p>=k && left<n){
                p/=nums[left];
                left++;
            }
             cnt+=right-left+1;
        }

        return cnt;
    }
};