class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            long long sum = prefix[i-1]+nums[i];
            prefix[i] = sum ;
        }
        int cnt=0;
        for(int i=0; i<n-1; i++){
            if(prefix[i] >= prefix[n-1] - prefix[i]) cnt++;
        }

        return cnt;

    }
};