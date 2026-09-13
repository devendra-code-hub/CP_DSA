class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,p=-1;
        for(int c: nums){
            if(cnt==0){
                
                p=c;
            }
           if(p==c) cnt++;
            if(p != c)cnt--;
        }
        return p;
    }
};