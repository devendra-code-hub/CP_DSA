class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        vector<int>v={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
        int mx=*max_element(nums.begin(), nums.end());
        for(int i=0; i<v.size()-1; i++){
            if(mx>v[i] && mx<v[i+1]) return v[i+1];
            else if( mx==v[i+1]) return v[i+1]*2;
        }
        return 1;
    }
};