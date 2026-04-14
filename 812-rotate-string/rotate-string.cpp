class Solution {
     
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string ns = s + s;
        return ns.find(goal) != string::npos;
        
         
        
    }
};