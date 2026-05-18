#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;  
        
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited_idx(n, false);
        
        q.push(0);
        visited_idx[0] = true;
        int steps = 0;

        
        while (!q.empty()) {
            int size = q.size();
            
             
            while (size--) {
                int curr = q.front();
                q.pop();

              
                if (curr == n - 1) return steps;

               
                if (curr - 1 >= 0 && !visited_idx[curr - 1]) {
                    visited_idx[curr - 1] = true;
                    q.push(curr - 1);
                }

                
                if (curr + 1 < n && !visited_idx[curr + 1]) {
                    visited_idx[curr + 1] = true;
                    q.push(curr + 1);
                }

                
                if (graph.count(arr[curr])) {
                    for (int next : graph[arr[curr]]) {
                        if (!visited_idx[next]) {
                            visited_idx[next] = true;
                            q.push(next);
                        }
                    }
                    
                    graph.erase(arr[curr]);
                }
            }
            steps++;
        }
        
        return -1;
    }
};