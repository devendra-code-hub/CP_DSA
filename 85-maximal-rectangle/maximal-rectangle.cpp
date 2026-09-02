class Solution {
public:
vector<int> NSE(vector<int>&v){
    int n=v.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && v[st.top()]>= v[i])st.pop();
        ans[i]=st.empty()?n-1:st.top()-1;
        st.push(i);
    }
    return ans;
}
vector<int> PSE(vector<int>&v){
    int n=v.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()]> v[i])st.pop();
        ans[i]=st.empty()?0:st.top()+1;
        st.push(i);
    }
    return ans;
}
int LRA(vector<int>&heights){
     int n=heights.size();
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        int ans=0;
        for(int i=0; i<n; i++){
            int w=nse[i]-pse[i]+1;
            ans=max(ans, w*heights[i]);
        }

        return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int>heights(m,0);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int mx = LRA(heights);
            ans=max(ans, mx);
        }
        return ans;
    }
};