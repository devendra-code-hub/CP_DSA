class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,p=1;
        for(auto c : nums){
            if(c==0)cnt++;
            else p*=c;
            }
        vector<int>ans(n,0);
        if(cnt>1)return ans;
        if(cnt==1){
            for(int i=0; i<n; i++){
                if(nums[i]==0) ans[i]=p;
            }
        }else{
            for(auto i=0; i<n; i++){
                ans[i]=p/nums[i];
            }
        }
    
     return ans;

    }
};