class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size(),mx=0;
        vector<int>pg;
        for(auto it: nums){
            mx=max(mx,it);
            int ans=gcd(mx,it);
            pg.push_back(ans);
        }
        sort(pg.begin(), pg.end());
        long long l=0,r=n-1,res=0;
        while(l<r){
            res+=gcd(pg[l], pg[r]);
            l++;
            r--;
        }
        
        return res;

    }
};