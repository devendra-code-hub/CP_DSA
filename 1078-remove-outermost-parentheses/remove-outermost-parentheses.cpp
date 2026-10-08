class Solution {
public:
    string removeOuterParentheses(string s) {
         string ans="";
         int n=s.size(), cnt=0;
         vector<int>v;
         for(auto c: s){
            if(c=='(')cnt++;
           else if(c==')')cnt--;
           v.push_back(cnt);
         }
         for(int i=1; i<n; i++){
            cout<<v[i];
            if(v[i]==0 || v[i-1]==0)continue;
           else ans+=s[i];
         }

         return ans;
    }
};