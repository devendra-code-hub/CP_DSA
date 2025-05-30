class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int>st;
        int mxlen=0;
        st.push(-1);
        for(int i=0; i<n; ++i){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }
                else{
                    mxlen=max(mxlen,i-st.top());
                }
            }
        }

        return mxlen;
    }
};