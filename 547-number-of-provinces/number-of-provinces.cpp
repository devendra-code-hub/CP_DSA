class Solution {
private:
    // dfs traversal function
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        // mark the node as visited
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size(); // Use adj.size() to get the number of rows (vertices)
        vector<vector<int>> adjLs(V);

        // to change adjacency matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // self nodes are not considered
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(V, 0); // Correctly initializes a vector of size V with all zeros
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            // if the node is not visited
            if (!vis[i]) {
                // counter to count the number of provinces
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};