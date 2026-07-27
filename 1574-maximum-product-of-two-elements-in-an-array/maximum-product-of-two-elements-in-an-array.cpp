class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),mx=0,mx2=0, idx=-1;
        for(int i=0; i<n; i++){
            if(mx<nums[i]){
                mx=nums[i];
                idx=i;
            }
        }
        for(int i=0; i<n; i++){
            if(i !=idx && mx2<nums[i] && mx2<=mx){
                mx2=nums[i]; 
            }
        }

        return (mx-1)*(mx2-1);

    }
};