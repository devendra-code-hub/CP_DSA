class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=1e9;
         vector<vector<pair<int,int>>>adj(n+1);
         for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
         }
         vector<bool>vis(n+1,false);
         queue<int>q;
         q.push(1);
         vis[1]=true;
         while(!q.empty()){
            int u=q.front();
            
            q.pop();
            for(auto it: adj[u]){
                int v=it.first;
                int w=it.second;
                ans=min(ans,w);
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
         }

         return ans;
    }
};