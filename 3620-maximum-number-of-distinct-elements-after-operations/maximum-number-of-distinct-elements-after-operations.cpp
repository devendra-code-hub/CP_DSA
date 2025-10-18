class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN; // track last chosen distinct number
        int count = 0;

        for (int num : nums) {
            // choose the smallest possible value within [num - k, num + k]
            long long start = num - k;
            long long end = num + k;

            // we must pick strictly greater than 'last'
            long long pick = max(start, last + 1);

            if (pick <= end) {
                count++;
                last = pick;
            }
        }

        return count;
        
        //   int n = nums.size();
        //   sort(nums.begin(), nums.end());
        //   vector<int>ch;
        //   for(int i=n-1; i>=0; i--){
        //     for(int j=k; j>=-k; j--){
        //         if(find(ch.begin(), ch.end(), nums[i]+j) == ch.end()){
        //             ch.push_back(nums[i]+j);
        //             break;
        //         }
        //     }
        //   }
        //   return ch.size(); 
    }
};
/*
int n = nums.size();
          vector<int>copy=nums;
          sort(nums.begin(), nums.end());
          vector<int>ch;
          vector<int>ch1;
          ch.push_back(nums[0]);
          ch1.push_back(copy[0]);
          for(int i=1; i<n; i++){
            if(find(ch.begin(), ch.end(), nums[i]) == ch.end()){
                ch.push_back(nums[i]);
            }else{
                for(int j=-k; j<=k; j++){
                    if(find(ch.begin(), ch.end(), nums[i] + j) == ch.end()){
                        ch.push_back(nums[i] +j);
                        break;
                    }
                }

            if(find(ch1.begin(), ch1.end(), copy[i]) == ch1.end()){
                ch1.push_back(nums[i]);
            }else{
                for(int j=k; j>=-k; j--){
                    if(find(ch1.begin(), ch1.end(),copy[i] + j) == ch1.end()){
                        ch1.push_back(copy[i] +j);
                        break;
                    }
                }
            }
          }
          }
          //return( ch.size()>n) ? n: ch.size() ;
          return  max(ch.size(),ch1.size());
*/