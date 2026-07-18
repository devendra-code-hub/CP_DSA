class Solution {
public:
    int gcd_c(int a, int b){
        if(b==0) return a;

        return gcd_c(b, a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(mx<nums[i]) mx=nums[i];
            if(mn>nums[i]) mn=nums[i];
        }
        return gcd_c(mx,mn);
    }
};