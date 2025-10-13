class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size() == 0) return {};
        int n = words.size();
        vector<string>ans;
        ans.push_back(words[0]);

        for(auto & s : words ){
            string curr = s;
            string check = ans.back();
            sort(curr.begin(), curr.end());
            sort(check.begin(), check.end());
            if(curr != check){
                ans.push_back(s);
            }
        }
        return ans;
    }
};
 // vector<string> ans;
        // vector<string>copy;
        // for(auto s: words){
        //       sort(s.begin(),s.end());
        //       string news = s;
        //     copy.push_back(news);
        // }
        // set<string>set_str;
        // for(auto s : copy){
        //     set_str.insert(s);
        // }
        // vector<string>extra;
        // for(auto s : words){
        //     string push_s = s;
        //     sort(s.begin(), s.end());
        //       string check = s;
        //     bool ch =0;
        //     for(auto it : set_str){
        //         if(it == check && find(extra.begin(), extra.end(), s) == extra.end() ){ 
        //             extra.push_back(s);
        //             ans.push_back(push_s);
        //             ch=1;
        //         }
        //     }
        //     if(ch == 0 && find(extra.begin(), extra.end(), s) == extra.end()) ans.push_back(push_s);
        // }

        // return ans;