class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        int i = n - 2;

        
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

         
        reverse(nums.begin() + i + 1, nums.end());
        // int n=nums.size();
        // int count=0;
        // for(int i=n-1; i>=1;--i){
        //      if(nums[i]>nums[i-1]){
        //         swap(nums[i],nums[i-1]);
        //         count++;
        //         break;
        //      }
        // }
        // if(count==0){
        //     reverse(nums.begin(),nums.end());
        // }
    }
};