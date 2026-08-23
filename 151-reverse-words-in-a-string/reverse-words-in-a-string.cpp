class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(), s.end());
        int cnt=0,i=0;
        while(i<n && s[i] ==' ')  i++;
        int j=n-1;
        while(j>=0 && s[j] == ' ')  j--;

        string ans="";
        for(int k=i; k<=j; k++) {
            if(s[k] !=' ')ans+=s[k];
            else if(ans.back() != ' ')ans+=' ';
        }
        int l=0;
        while(l<ans.size()){
            int k=l;
            while(k<ans.size() && ans[k] != ' ')k++;
            reverse(ans.begin()+l, ans.begin()+k);
            l=k+1;
        }

        return ans;


    }
};