class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        // Check for 32-bit signed integer overflow
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;

        return static_cast<int>(rev);

        // long long rev = 0;   
        // int num = x;
        //  if (x < 0) num=abs(x);

        // while (num != 0) {
        //     int digit = num % 10;
        //     rev = rev * 10 + digit;
        //     num = num / 10;
        // }
        // if(x<0) return (-1)*rev;

        // // return rev;
        // if (rev < INT_MIN || rev > INT_MAX)
        //     return 0;

        // return static_cast<int>(rev);
    }
};