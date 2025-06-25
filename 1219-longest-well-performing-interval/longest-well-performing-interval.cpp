class Solution {
public:
    int longestWPI(vector<int>& hours) {
       unordered_map<int, int> firstSeen;
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < hours.size(); ++i) {
        
        prefixSum += (hours[i] > 8) ? 1 : -1;

        if (prefixSum > 0) {
             
            maxLength = i + 1;
        } else {
            
            if (firstSeen.find(prefixSum - 1) != firstSeen.end()) {
                maxLength = max(maxLength, i - firstSeen[prefixSum - 1]);
            }
        }

        
        if (firstSeen.find(prefixSum) == firstSeen.end()) {
            firstSeen[prefixSum] = i;
        }
    }

    return maxLength;
    }
};