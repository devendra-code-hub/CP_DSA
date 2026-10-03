class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, ans=0;
        for(int c: nums){
            if(c==1)cnt++;
            else {
                ans=max(ans, cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);

        return ans;
    }
};