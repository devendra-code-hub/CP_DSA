class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0, mx=0,curr_end=0;
        if(nums.size()==1)return 0;
        for(int i=0; i<nums.size()-1; i++){ 
             
            mx=max(mx, i+nums[i]);
            if(i==curr_end){
            cnt++;
            curr_end=mx;

            if(curr_end>=nums.size()-1) break;
            }
             
            
        }

        return cnt;
    }
};