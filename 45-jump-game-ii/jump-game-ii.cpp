class Solution {
public:
    int jump(vector<int>& nums) {
     int n=nums.size();
     int farthest=0,step=0,curr_idx=0;
     for(int i=0; i<n-1; ++i){
         farthest=max(farthest,i+nums[i]);
        if(i==curr_idx){
            step++;
            curr_idx=farthest;
        }
       
     }
     return step;
    }
};