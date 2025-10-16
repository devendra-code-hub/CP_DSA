class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
         unordered_map<int,int> cnt;
        for (int x : nums) {
            int r = ((x % value) + value) % value;  
            cnt[r]++;
        }

        int mex = 0;
        while (true) {
            int r = mex % value;
            if (cnt[r] == 0) break;
            cnt[r]--;   
            mex++;
        }
        return mex;
    }
};
/*
int n=nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i]%value;
            if(nums[i]<0) nums[i] = value + nums[i];
        //    if(nums[i]>value/2) nums[i] = value-nums[i];
        }
       
        long long mx = *max_element(nums.begin(), nums.end());
        for(int i=0; i<= mx+1; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                return i;
            }
        }
        return 0;
*/