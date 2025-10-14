class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1) return true;
        for(int i=0; i<n-2*k+1; i++){
            int cnt1=0,cnt2=0;
            for(int j=i; j<k+i-1; j++){
                if(nums[j+1]>nums[j] ) cnt1++;
                else break;

                if(cnt1 == k-1) break;
            }
            for(int l=k+i; l<(2*k+i-1); l++){
                if(nums[l+1]>nums[l] ) cnt2++;
                else break;

                if(cnt2 == k-1) break;
            }

            if(cnt1 == cnt2 && cnt1 == k-1) return k-1;
        }

        return false;
    }
};