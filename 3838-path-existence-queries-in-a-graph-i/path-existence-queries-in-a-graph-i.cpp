class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int current_comp = 0; 
        for (int i = 1; i < n; i++) { 
            if (nums[i] - nums[i-1] > maxDiff) {
                current_comp++;
            }
            component[i] = current_comp;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        
         
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1]; 
            ans.push_back(component[u] == component[v]);
        }
        
        return ans;
    }
};