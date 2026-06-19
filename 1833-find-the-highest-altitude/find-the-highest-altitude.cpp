class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev=0,mx=0;
        for(auto c: gain){
            mx=max(mx,c+prev);
            prev+=c;
        }

        return mx;
    }
};