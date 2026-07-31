class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>f(26,0);
        for(auto c: word) f[c-'a']++;
        sort(f.begin(), f.end());
        int cnt=1, ans=0;
        for(int i=25; i>=0; i--){
            if(cnt<= 8 && f[i]){
                ans+=f[i];
                cnt++;
            }else if(cnt>8 && cnt<=16 && f[i]){
                ans+=f[i]*2;
                cnt++;
            }else if(cnt>16 && cnt<=24 && f[i]){
                ans+=f[i]*3;
                cnt++;
            }else if(f[i]){
                ans+=f[i]*4;
                cnt++;
            }
        }

        return ans;
    }
};