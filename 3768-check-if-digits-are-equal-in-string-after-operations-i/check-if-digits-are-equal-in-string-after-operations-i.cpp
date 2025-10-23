class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string s2 ="";
        s2 = s;
        while(n-- >= 2){
            string s1 ="";
            for(int i=0; i<s2.size() -1; ++i){
                int sum = (s2[i] + s2[i+1])%10;
                char c = sum;
                s1 += c;
                  
            }
            if(s1.size()== 2 && s1[0] == s1[1] ) return true;
            s2 = s1;
        }
        return false;
    }
};