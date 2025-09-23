class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>vis(256,0);
        int i=0,ans=0;
        while(i<n){
            int j=i;
            while(j<n && !vis[s[j]]  ){ 
                vis[s[j]] =1;
                j++;
            } 
                ans = max(ans,j-i); 
                 for(int k=0; k<n; k++){
                    if(vis[s[k]] == 1) vis[s[k]] = 0;
                 }

                i++; 
        }
        return ans;
    }
}; 