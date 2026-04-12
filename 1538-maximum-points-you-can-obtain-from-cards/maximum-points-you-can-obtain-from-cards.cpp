class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            int leftsum=0,rightsum=0,score=0;
            for(int i=0; i<k; ++i){
                leftsum += cardPoints[i];
            }
            score = leftsum;
           int j=n-1;
            for(int i=k-1; i>=0; --i){
                leftsum -= cardPoints[i];
                rightsum +=cardPoints[j];
                j--;
                score = max(score,leftsum + rightsum );
            }
            return score;
         
        // int n=cardPoints.size();
        //  int r=1,score=0;
        // if(n==1)  return  cardPoints[0] ;
        //  score= max(cardPoints[0],cardPoints[1]) ; 
        //  while(r<n-k){
        //     int sum=0;
        //     for(int i=r; i<r+k; ++i){
        //         sum += cardPoints[i];
        //     }
        //     score =max(score,sum);
        //     r++;

        //  }
        //  return score;
    }
};
// int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
//         int windowSize = n - k;
//         int currentSum = 0;

//         // Calculate the sum of the initial window
//         for (int i = 0; i < windowSize; ++i) {
//             currentSum += cardPoints[i];
//         }

//         int minSum = currentSum;

//         // Slide the window across the array
//         for (int i = windowSize; i < n; ++i) {
//             currentSum += cardPoints[i] - cardPoints[i - windowSize];
//             minSum = min(minSum, currentSum);
//         }

//         return totalSum - minSum;