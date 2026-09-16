class Solution {
public:
bool check(vector<int>&nums, int k, int h){
    int n=nums.size();
    long long ans=0;
    for(int i=0; i<n; i++){
        if(nums[i]%k==0)ans+=nums[i]/k;
        else ans+=(nums[i]/k)+1;
    }

    return ans<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(), piles.end());
        int ans=INT_MAX;
        while(l<=r){
            int m=(l+r)/2;
            if(check(piles, m, h)){
                ans=min(ans,m);
                r=m-1;
            }else l=m+1;
        }

        return ans;
    }
};