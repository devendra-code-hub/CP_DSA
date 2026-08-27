class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int st=0,len=-1;
        
            for(int i=0; i<n; i++){
                for(int p=0; p<=1; p++){
                int l=i,r=i+p;
                while(l>=0 && r<n && s[l]==s[r]){
                    if(len<r-l+1){
                        len=r-l+1;
                        st=l;
                    }
                    l--;
                    r++;
                }
             }
            }
       
       

        return s.substr(st,len);
    }
};