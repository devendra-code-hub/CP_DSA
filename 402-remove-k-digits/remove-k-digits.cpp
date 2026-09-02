class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        vector<char>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && s.back()>num[i] && k>0){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        while(k>0){
            s.pop_back();
            k--;
        }
        string ans="";
        int i=0;
        while(i<s.size() && s[i]=='0') i++;
        for(; i<s.size(); i++)  {
            ans+=s[i];
        }

        return ans==""?"0":ans;
    }
};