class Solution {
public:
int gcd_c(int a, int b){
    if(b==0) return a;
    return gcd_c(b,a%b);
}
    int gcdOfOddEvenSums(int n) {
        // int so=0,se=0,cnt=0;
        // for(int i=1; i<=2*n; i++){
        //     if(i&1)so+=i;
        //     else se+=i;
        // }
        // return gcd_c(so,se);
        return n;
    }
};