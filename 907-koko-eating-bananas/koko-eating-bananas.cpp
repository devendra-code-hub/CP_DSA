class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int hi=*max_element(piles.begin(), piles.end());
        int l=1 , ans=INT_MAX;
        while(l<=hi){
            int m=(l+hi)/2;
            long long t=0;
            for(auto c : piles) t+= ceil((double)c/m);
            if(t <= h){
                ans=min(ans,m);
                hi=m-1;
            }else{
                l=m+1;
            }
        }

        return ans;
    }
};