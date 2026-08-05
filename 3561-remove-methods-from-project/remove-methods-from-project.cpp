class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>suspicious(n,0);
        vector<vector<int>>adj(n);
        for(auto & it : invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);

        }
        queue<int>q;
        q.push(k);
        suspicious[k]=1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!suspicious[it]){
                    suspicious[it]=1;
                    q.push(it);
                }
            }
        }
        bool check=true;
        for(auto it : invocations){
            int u=it[0];
            int v=it[1];
            if(!suspicious[u] && suspicious[v]){
                check=false;
                break;
            }
        }
        vector<int> ans;
        if(!check){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }else{
            for(int i=0; i<n; i++){
                if(!suspicious[i]){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};