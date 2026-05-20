class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int>mp;
        int ans=0;
        vector<int>res;
        for(int i=0; i<n; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]]==2){ans++; mp.erase(A[i]);}
            if(mp[B[i]]==2){ans++; mp.erase(B[i]);}
            res.push_back(ans);
        }

        return res;
    }
};