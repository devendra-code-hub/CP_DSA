class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<string>res;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=i; j<n; j++){
                if(s[j]=='1')cnt++;
                if(cnt==k)res.push_back(s.substr(i,j-i+1));
            }
        }
        sort(res.begin(), res.end());
        string ans="";
        int mn=INT_MAX;
        for(auto c: res){
            int size=c.size();
            if(size<mn){
                mn=size;
                ans=c;
            }
        }
        return  ans;
    }
};