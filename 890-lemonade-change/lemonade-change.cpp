class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        // sort(bills.begin(), bills.end());
        unordered_map<int,int>mp;
        for(auto c: bills){
            if(c==10){
                if(mp[5]>=1) mp[5]--;
                else return false;
                mp[c]++;
            }else if(c==20){
                if((mp[5]>=1 && mp[10]>=1) || (mp[5]>=3)){
                    if(mp[5]>=1 && mp[10]>=1){
                        mp[5]--;
                        mp[10]--;
                    }else {
                        mp[5]--;
                        mp[5]--;
                        mp[5]--;
                    }
                    mp[c]++;
                }else return false; 
            }else{
                mp[c]++;
            }
        }
        return true;
        
        

    }
};