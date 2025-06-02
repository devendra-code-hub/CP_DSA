class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
       vector<string>ans(n);
       priority_queue<pair<int,int>>hp;
       for(int i=0; i<n; i++){
        hp.push({score[i],i});
       }
       int place=0;
       while(!hp.empty()){
        int idx=hp.top().second;
        hp.pop();
        if(place==0){
           ans[idx]="Gold Medal";
        }
        else if(place == 1){
            ans[idx]="Silver Medal";
        }
         else if(place == 2){
            ans[idx]="Bronze Medal";
        }
        else{
            ans[idx]=to_string(place+1);
        }
        place++;
       }
       return ans;
       
    }
};