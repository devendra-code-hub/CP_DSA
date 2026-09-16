class Solution {
public:
bool check(vector<int>&nums, int c, int days){
    int n=nums.size(), ans=1, sum=0;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        if(sum>c){
            ans++;
            sum=nums[i];
        }
    }
     

    return ans<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end()), r=accumulate(weights.begin(), weights.end(),0), ans=INT_MAX;
        while(l<=r){
            int m=(l+r)/2;
            if(check(weights, m, days)){
                ans=min(ans, m);
                r=m-1;
            }else l=m+1;
        }

        return ans;
    }
};