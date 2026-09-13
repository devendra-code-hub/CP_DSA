class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0; i<n-2; i++){
        // for(int j=i+1; j<n; j++){
            // for(int k=j+1; k<n; k++){
            if(i>0 &&  nums[i]== nums[i-1])continue;
            int l=i+1, r=n-1;
            // if(l<n && nums[i]==nums[l])continue;
            while(l<r){
                int sum =nums[i]+nums[l]+nums[r];
                vector<int>v={nums[i],nums[l],nums[r]};
                if(sum==0){ 
                ans.push_back(v);
                while(l<r && nums[l]==nums[l+1])l++;
                while(l<r && nums[l]==nums[r-1])r--;
                l++;
                r--;
                }else if(sum<0) l++;
                else r--;
            }
                // sort(v.begin(), v.end());
                
                // if(sum==0 && find(ans.begin(), ans.end(), v) == ans.end()) ans.push_back( v);
            // }
        // }
    }
    return ans;
    }
};