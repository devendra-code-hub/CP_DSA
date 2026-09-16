class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,n=nums.size();
        while(l<r){
            int m=(l+r)/2;
            if(m>0 && m<n-1 && nums[m-1]>= nums[m] && nums[m]<=nums[m+1])return nums[m];
            else if(nums[m]<=nums[r])r=m-1;
            else l=m+1;
        }

        return  nums[l];
    }
};