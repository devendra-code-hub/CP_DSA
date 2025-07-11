class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int i=0,j=n-1;
        int sum=0; vector<int>ans;
        while(i<j){
            sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};