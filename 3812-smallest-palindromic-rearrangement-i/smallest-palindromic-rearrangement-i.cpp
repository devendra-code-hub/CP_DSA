class Solution {
public:
 
    string smallestPalindrome(string s) {
        vector<int>v(26,0);
        int n=s.size();
        for(auto c: s) v[c-'a']++;
        string ans="";
        int idx=-1;
        for(int i=0; i<26; i++){
            if(v[i]%2==1) idx=i;
            
            int f=(v[i])/2;
            v[i]-=f;
            while(f--){
                ans+= i+'a';
            }     
     }

     if(idx >= 0 && v[idx]) {
        ans+= idx + 'a';
         v[idx]-=1;
        }

        for(int i=25; i>=0; i--){
            int f=v[i];
            while(f--){
                ans+='a'+i;
            }
        }
 

        return ans;
    }
};