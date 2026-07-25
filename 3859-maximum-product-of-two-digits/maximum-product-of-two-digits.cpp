class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n){
            int res =n%10;
            v.push_back(res);
            n=n/10;
        }
        int mx=0;
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(i!=j) mx=max(mx,v[i]*v[j]);
            }
        }

        return mx;
    }
};