class Solution {
public:
long long gcd_c(int a, int b){
    if(b==0) return a;

    return gcd_c(b, a%b);
}
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        using ll= long long;
        ll mx=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    ll g= gcd_c(nums[i], nums[j]);
                    mx=max(mx, (1LL*nums[i]*nums[j])/(g*g) );
                }
            }
        }

        return mx;
    }
};