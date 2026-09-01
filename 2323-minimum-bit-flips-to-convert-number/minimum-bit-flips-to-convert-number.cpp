class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal, cnt=0;
        while(n){
            int rem=n%2;
            if(rem==1)cnt++;
            n/=2;
        }
        return cnt;
    }
};