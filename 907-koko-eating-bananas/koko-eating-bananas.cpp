class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1,r=*max_element(piles.begin(), piles.end()),ans=0;
        while(l<=r){
            long long m=(l+r)/2;
            long long cnt=0;
            for(int i=0; i<piles.size(); i++){
                if(piles[i]%m != 0) cnt+=(piles[i]/m)+1;
                else cnt+=(piles[i]/m);
            }

            if(cnt<=h){
                ans=m;
                r=m-1;
            }else l=m+1;
        }

        return int(ans);
    }
};