class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N=tasks.size();
        vector<int>ans(26,0);
        for(int i=0; i<N; ++i){
            ans[tasks[i]-'A']++;
        }
        sort(ans.begin(),ans.end());
        int res,sub=0;
    //   for(int i=0; i<25; ++i){
    //     if(ans[i]>0)  
    //         sub+=(ans[i]-1);
    //     }
      //  res=n*(ans[25]-1)-sub;
       res=(ans[25]-1);
       int slots=n*res;
       for(int i=24; i>=0 && ans[i]>0; i--){
        slots-=min(res,ans[i]);
       }
       
        
     
        
        return slots>0 ? slots+N : N;
    }
};