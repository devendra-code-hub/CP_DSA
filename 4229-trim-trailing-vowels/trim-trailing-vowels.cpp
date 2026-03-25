class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'a' ||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
            else break;
        }

        return s.substr(0,n-cnt);
    }
};