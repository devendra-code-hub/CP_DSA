class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();
        int sign = 1;
        while(i<n && s[i]==' ') i++;
        if(i<n &&(s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        while(i<n && s[i]=='0')i++;

        int j=n-1;
        while(j>=0 &&  s[j]==' ') j--;
        string ans="";
        for(int k=i; k<=j; k++){
            if(s[k]>='0' && s[k]<='9')ans+=s[k];
            else break;
        }
     long res=0;
        for(auto c: ans){
            res=res*10 + (c-'0');
            if(sign ==-1 && -res<INT_MIN) return INT_MIN;
            if(sign ==1 && res>INT_MAX) return INT_MAX;
        }
        return sign*res;
    }
};