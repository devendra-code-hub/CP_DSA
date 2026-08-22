class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int n=s.size();
        vector<int>l(n,0),r(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i] =='('){
                cnt++;
                l[i]=cnt;
           }else{
            cnt--;
            l[i]=cnt;
           }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i] =='('){
                cnt--;
                r[i]=cnt;
           }else{
            cnt++;
            r[i]=cnt;
           }
        }
         
        for(int i=0; i<n; i++){
            if(l[i] == 0 || r[i] ==0) continue;
            ans+=s[i];
        }

        return ans;

    }
};