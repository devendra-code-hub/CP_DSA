class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0 ) return false;
     map<int,int>mp;
     for(auto h : hand) mp[h]++;

     for(auto [h,freq] : mp){
        if(freq==0) continue;
        while(freq--){
            for(int cur=h; cur<h+groupSize; cur++){
                if(mp[cur]==0) return false;
                mp[cur]--;
            }
        }
     }

     return true;
    }
};