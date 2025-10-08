class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>ans;
        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++){
            int low = 0,high =m-1;
            while(low<=high){
                int mid = low + (high-low)/2;
               long long check = 1LL*spells[i]*potions[mid];
               if(check >= success){
                high = mid-1;
               }else{
                low = mid+1;
               }
            }
            ans.push_back(m-low);
        }
        // for(int i=0; i<n; i++){
        //     int cnt = 0;
        //     for(int j=0; j<m; j++){
        //         long long check = 1LL*spells[i]*potions[j];
        //         if( check >= success) cnt++;
        //     }
        //     ans.push_back(cnt);
        // }

        return ans;
        
    }
};