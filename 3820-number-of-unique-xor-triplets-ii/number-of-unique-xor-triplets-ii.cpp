class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>s;
        vector<int>u;
        for(int it : nums){
            if(s.find(it) == s.end()){
            s.insert(it);
            u.push_back(it);
        }
        }
        vector<bool>u_pair(2048,false);
        int n=s.size();
        for(int i=0; i<n; i++ ){
            for(int j=i+1; j<n; j++){
                u_pair[u[i]^u[j]]=true;
            }
        }
        vector<int>trip(2048, false);
        for(int it : u) trip[it]=true;
        for(int i=0; i<2028; i++){
            if(u_pair[i]){
                for(int it : u){
                    trip[i^it]=true;
                }
            }
        }
        int ans=0;
        for(int i=0; i<2048; i++){
            if(trip[i]) ans++;
        }

     return ans;
    }
};