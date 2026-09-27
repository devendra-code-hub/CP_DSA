class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>v;
        for(int i=0; i<n; i++){
            if(s[i]=='(')v.push_back(i);
            else if(s[i]==')'){
                reverse(s.begin()+v.back()+1, s.begin()+i);
                v.pop_back();
            }
        }
        string ans="";
        for(auto c: s){
            if(c!= '(' && c!=')')ans+=c;
        }

        return ans;
    }
};