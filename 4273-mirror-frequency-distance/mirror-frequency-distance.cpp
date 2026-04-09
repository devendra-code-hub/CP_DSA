class Solution {
public:
    int mirrorFrequency(string s) {
        int freq[256] = {0};
        for (char ch : s) {
            freq[(unsigned char)ch]++;
        }

        int ans = 0;
        bool processed[256] = {false};

        for (int i = 0; i < 256; i++) {
            if (freq[i] == 0 || processed[i]) continue;

            char ch = (char)i;
            char mirror;

            if (ch >= '0' && ch <= '9') {
                mirror = '9' - ch + '0';
            } else if (ch >= 'a' && ch <= 'z') {
                mirror = 'z' - ch + 'a';
            } //else {
            //     // If the character isn't a digit or lowercase letter, 
            //     // it's its own mirror or doesn't pair
            //     ans += freq[i];
            //     processed[i] = true;
            //     continue;
            // }

            // Calculate the difference between the char and its mirror
            ans += abs(freq[ch] - freq[mirror]);

            // Mark both as processed so we don't count the pair again
            processed[(unsigned char)ch] = true;
            processed[(unsigned char)mirror] = true;
        }

        return ans;
        // int n=s.size();
        // unordered_map<char,int>freq;
        // for(int i=0; i<n; i++) freq[s[i]]++;
        // int ans=0;
        // vector<char>v;
        // for(auto & it : freq){
        //     char ch = it.first;
        //     if(ch>='0' && ch<='9'){ 

        //         int ad='9'-ch;
        //         bool f1 =find(v.begin(), v.end(), ch) == v.end();
        //         bool f2 =find(v.begin(), v.end(),char(ad+'0')) == v.end();
        //         if(f1 && f2){
        //         ans+=abs(freq[ch] - freq[char(ad+'0')]);
        //         v.push_back(ch);
        //         v.push_back(char(ad+'0'));
        //         }
        //     }else{
        //         int ad = 'z'-ch;
        //         bool f1 =find(v.begin(), v.end(), ch) == v.end();
        //         bool f2 =find(v.begin(), v.end(),char(ad+'a')) == v.end();
        //         if(f1 && f2){
        //         ans+=abs(freq[ch] - freq[char(ad+'a')]);
        //         v.push_back(ch);
        //         v.push_back(char(ad+'a'));
        //         }
        //     }
        // }
        // return ans;
    }
};