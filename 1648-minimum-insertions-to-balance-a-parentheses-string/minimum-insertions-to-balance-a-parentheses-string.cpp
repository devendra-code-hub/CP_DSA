class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_right = 0;
        
        for (char c : s) {
            if (c == '(') {
              
                if (needed_right % 2 != 0) {
                    insertions++;      
                    needed_right--;     
                }
                needed_right += 2; 
            } 
            else {  
                needed_right--;   
                if (needed_right < 0) {
                    insertions++;       
                    needed_right = 1;    
                }
            }
        } 
        return insertions + needed_right;
    }
};