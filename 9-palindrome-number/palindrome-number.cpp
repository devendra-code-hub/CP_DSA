class Solution {
public:
    bool isPalindrome(int x) {
      long long rev = 0;
         int num=x;
         if(x<0) return false;

    while (num != 0) {
        int digit = num % 10;       
        rev = rev * 10 + digit;    
        num = num / 10;            
    }
    if(rev == x) return true;

    return false;
    }
};