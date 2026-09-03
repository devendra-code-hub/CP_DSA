class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int ans=0,l=0, n=fruits.size();
        for(int r=0; r<n; r++){
            mp[fruits[r]]++;
            while(l<=r && mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            ans=max(ans, r-l+1);
        }

        return ans;
    }
};