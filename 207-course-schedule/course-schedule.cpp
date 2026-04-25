class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        int n = prerequisites.size();
        int m = prerequisites[0].size();
         
        vector<vector<int>>adj(numCourses);
        for(int i=0; i<n; i++){
             int st =prerequisites[i][1];
             int ed =prerequisites[i][0];
                adj[st].push_back(ed);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto nbr : adj[i]){
                indegree[nbr]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        if(cnt == numCourses) return true;

        return false;
    }
};