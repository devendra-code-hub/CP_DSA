class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        if((n>=1e3) ) ans+=n-1e3 +1;
        // if(n==1e5) ans+=n-1;

        return ans;
    }
};