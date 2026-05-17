class Solution {
public:
bool check(int idx, int n, vector<bool>&vis, vector<int>&arr){
    if(idx>=n || idx<0) return false;
    if(arr[idx] == 0) return true;
    if(vis[idx]) return false;
    vis[idx]=true;
    bool a=check(idx+arr[idx],n,vis,arr);
    bool s=check(idx-arr[idx],n,vis,arr);

    return vis[idx]=a||s;
}
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
        return check(start,n,vis,arr);
    }
};