class Solution {
    private:
        vector<int>digit(int n){
            vector<int>d;
            while(n){
                int x=n%10;
                d.push_back(x);
                n=n/10;
            }
            reverse(d.begin(), d.end());
            return d;
        }
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1; i<=num2; i++){
            vector<int>d=digit(i);
            if(d.size()>2){
                for(int j=1; j<d.size()-1; j++){
                    if((d[j]>d[j+1]  && d[j]>d[j-1]) || (d[j]<d[j-1] && d[j]<d[j+1])) ans++;
                }
            }
        }

        return ans;
    }
};