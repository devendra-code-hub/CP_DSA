class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        using ll=long long;
        ll ans=0;
        if(n==1) return s;
        // if(n&1){
            ll a=s;
            ll d=m-1;
            ll t=(n+1)/2;
            ans=max(ans,a+(t-1)*d);
        // }else{
             a=s+m;
            d=m-1;
             t=n/2;
            ans=max(ans,a+(t-1)*d);
        // }

        return ans;
    }
};