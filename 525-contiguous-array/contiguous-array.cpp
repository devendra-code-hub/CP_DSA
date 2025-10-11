class Solution {
public:
    int findMaxLength(vector<int>&v) {
        int n = v.size();
        int ans=0;
        unordered_map<int,int>mp;
        vector<int>prefix(n);
        if(v[0] == 0) prefix[0] = -1;
        else prefix[0] = 1;

        for(int i=1; i<n; i++){
            if(v[i] == 0) prefix[i] = prefix[i-1]-1;
            else prefix[i] = prefix[i-1]+1;
        }

        mp[0]=-1;
        for(int i=0; i<n; i++){
            if(mp.find(prefix[i]) != mp.end()){
                ans = max(ans, i-mp[prefix[i]] );
            }else{
            mp[prefix[i]]=i;
            }
        }
       

        return ans;
        
    }
};
/*
 for(int j=0; j<n; j++){
             int cnt0=0,cnt1=0;
        for(int i=j;i<n; i++){
            if(v[i] == 0) cnt0++;
            if(v[i] == 1) cnt1++;
            if(cnt0 - cnt1 == 0) ans=max(ans,cnt0*2);
        }}
*/