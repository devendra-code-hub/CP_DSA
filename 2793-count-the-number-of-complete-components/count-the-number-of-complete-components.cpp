class Solution {
public:
   void dfs(int node, int &cntV, int &cntE, vector<int>&vis, vector<vector<int>>&adj){
    vis[node]=1;
    cntV++;
    cntE+=adj[node].size();
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr,cntV,cntE,vis,adj);
        }
    }
   }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int cntV=0,cntE=0;
                dfs(i,cntV,cntE,vis,adj);
                if(cntE == cntV*(cntV-1)) ans++;
            }
        }

        return ans;
    }
};