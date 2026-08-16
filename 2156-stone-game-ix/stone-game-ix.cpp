class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0=0, c1=0,c2=0;
        for(auto num : stones){
            int r=num%3;
            if(r==0)c0++;
            if(r==1)c1++;
            if(r==2)c2++;
        }
        if(c0%2 == 0){
            return (c1>0 && c2>0);
        }else{
            return abs(c1-c2)>2;
        }
    }
};