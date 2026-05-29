class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            int num=nums[i],sum=0;
            while(num){
                int x=num%10;
                sum+=x;
                num=num/10;
            }
            ans=min(ans,sum);

        }
        return ans;
        
    }
};