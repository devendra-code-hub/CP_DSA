class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            int d=p.first;
            int r=p.second.first;
            int c=p.second.second;
             if(r==n-1 && c==m-1) return  d;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newEffort=max(abs(heights[r][c]-heights[nr][nc]), d);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        q.push({newEffort,{nr,nc}});
                        
                    }
                }
            }
        }

        return 0;
    }
};