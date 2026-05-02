class Solution {
private:
    bool check(int n) {
        bool hasChangingDigit = false;

        while (n > 0) {
            int digit = n % 10;

            // Test 1: Reject illegal digits immediately
            if (digit == 3 || digit == 4 || digit == 7) {
                return false; 
            }

            // Test 2: Mark if we found a digit that changes (2, 5, 6, 9)
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasChangingDigit = true;
            }

            n /= 10;
        }

        // It's only "Good" if it had no illegal digits AND at least one changing digit
        return hasChangingDigit;
    }

public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i)) cnt++;
        }
        return cnt;
    }
};


// class Solution {
//     private :
//      bool check (int n,unordered_map<int,int>&mp){
//         vector<int>v;
//         while(n>0){
//             v.push_back(n%10);
//             n/=10;
//         }
       
//         for(auto & it : v){
//             if(it == 3 || it == 4 || it == 7) return false;
//             if(mp.find(it) != mp.end() )return true;
//         }

//         return false;
//      }
// public:
//     int rotatedDigits(int n) {
//         unordered_map<int,int>mp;
//         mp[2]=1;
//         mp[5]=1;
//         mp[6]=1;
//         mp[9]=1;
//         int cnt=0;
//         for(int i=1; i<=n; i++){
//             if(check(i,mp)) cnt++;
//         }
         
//         return cnt;
//     }
// };