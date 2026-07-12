class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      int n = arr.size();
         
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> mp;
        int rank = 1;  
        
        for(int i = 0; i < n; i++){
            
            if(mp.find(sortedArr[i]) == mp.end()) {
                mp[sortedArr[i]] = rank;
                rank++; 
            }
        }
        
         
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};