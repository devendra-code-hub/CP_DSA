class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll=long long;
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        vector<ll>dist(n,1e18),ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int m=(int)(1e9+7);
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            ll c_d=curr[0];
            ll node=curr[1];
            if(c_d> dist[node]) continue;
            for(auto it : adj[node]){
                ll nbr=it.first;
               ll w=it.second;
                if(c_d+w <dist[nbr]){
                    dist[nbr]=c_d+w;
                    ways[nbr]=ways[node];
                    pq.push({c_d+w,nbr});
                }
                else if(c_d + w == dist[nbr]){
                    ways[nbr]=(ways[nbr]+ways[node])%m;
                }
            }
        }
        return ways[n-1]%m;
    }
};