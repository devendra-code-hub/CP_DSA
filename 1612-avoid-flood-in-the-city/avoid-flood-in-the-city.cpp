class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); 
        unordered_map<int, int> full;  
        set<int> dryDays;  
        
        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                 
                dryDays.insert(i);
            } else {
                ans[i] = -1;  
                
                if (full.count(lake)) {
                     
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) {
                        return {};  
                    }
                    ans[*it] = lake; 
                    dryDays.erase(it);  
                }
                full[lake] = i; // mark this lake as full on day i
            }
        }
        return ans;
        // int n = rains.size();
        // vector<int>st;
        // vector<int>ans;
        // for(int i=0; i<n; i++){
        //     auto it = find(st.begin(), st.end(), rains[i]);
        //     if(it != st.end()){
        //         break;
        //     }else if(rains[i] == 0 && st.empty()){
        //         ans.push_back(1);
        //     }else if(rains[i] == 0 && !st.empty()){
        //         ans.push_back(st.back());
        //         st.pop_back();
        //     }else{
        //         ans.push_back(-1);
        //         st.push_back(rains[i]);
        //     }
        // }
        // if(ans.size() == n) return ans;

        // return {};
    }
};