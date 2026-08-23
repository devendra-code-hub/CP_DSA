class Solution {
public:
    bool rotateString(string s, string goal) {
         int n=s.size();
         for(int i=0; i<=n; i++){
            string ans="";
            for(int j=0; j<n; j++){
                ans+=s[(j-i+n)%n];
            }
            if(ans ==goal) return true;
         }
         return false;
    }
};