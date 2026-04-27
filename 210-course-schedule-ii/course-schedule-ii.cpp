class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())  {
            vector<int>ans;
            for(int i=numCourses-1; i>=0; i--) ans.push_back(i);
            return ans;
        }
        vector<vector<int>>adj(numCourses);
        int n =prerequisites.size();
        for(int i=0; i<n; i++){
            int st=prerequisites[i][1];
            int ed=prerequisites[i][0];
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
        vector<int> ans;
        while(!q.empty()){
            int p =q.front();
            q.pop();
            ans.push_back(p);
            for(auto nbr : adj[p]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        if(ans.size() == numCourses) return ans;

        return {};

    }
};