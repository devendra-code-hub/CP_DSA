class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int ans=INT_MAX,mn=INT_MAX;
        for(int i=0; i<n; i++){
            if(capacity[i]>= itemSize && capacity[i]<=mn){
             if(capacity[i] < mn )   ans=i;
             else ans=min(ans,i);
                mn=capacity[i];
            }
        }
        return ans==INT_MAX? -1 : ans;

    }
};