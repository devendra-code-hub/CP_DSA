class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        unordered_map<int,int>idx;
        for(int i=0; i<n;++i){
            idx[score[i]]=i;
        }
        vector<string>ans(n);
        sort(score.begin(),score.end());
        reverse(score.begin(),score.end());
        for(int i=0; i<n; ++i){
            if(i==0){
                ans[idx[score[i]]]="Gold Medal";
            }
            else if(i==1){
                ans[idx[score[i]]]="Silver Medal";
            }
            else if(i==2){
                ans[idx[score[i]]]="Bronze Medal";
            }
            else{
                ans[idx[score[i]]]=to_string(i+1) ;
            }
        }
        return ans;
       
    }
};