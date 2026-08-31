class Solution {
public:
static bool comp(const vector<int> &a, const vector<int> & b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans=0,p2=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(p2>intervals[i][0]){
               ans++;
            }else{
                p2=intervals[i][1];
            }
        }
        return ans;
    }
};