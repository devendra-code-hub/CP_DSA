#include <vector>
#include <queue>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;

    // Your existing Fast Exponentiation function
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // Number of nodes is edges + 1
        
        // 1. Build the Adjacency List
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. BFS to find the maximum depth (number of edges L)
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int L = -1; // Start at -1 so the first node (root) makes it 0 edges
        
        while (!q.empty()) {
            int size = q.size();
            L++; // Each level we go deeper adds 1 to our max edge distance
            
            while (size--) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        
        // 3. The answer is just 2^(L-1) % MOD
        if (L <= 0) return 0;
        return power(2, L - 1);
    }
};