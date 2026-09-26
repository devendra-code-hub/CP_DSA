class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto it: knowledge){
            mp[it[0]]=it[1];
        }
        string ans="";
        int n=s.size();
        for(int i=0; i<n; ){
            if(s[i]=='('){
                string ns = "";
                int idx=i+1;
                while(idx<n && s[idx] != ')'){
                    ns+=s[idx];
                    idx++;
                }
                i=idx+1;

                if(mp.find(ns) != mp.end()){
                    ans+=mp[ns];
                }else ans+='?';
            }else{
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
};