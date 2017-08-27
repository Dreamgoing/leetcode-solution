class Solution {
public:
    int longestValidParentheses(string s) {
         int res = 0;
        int len = (int)s.length();
        vector<int> dp(len+1,0);
        stack<pair<char,int> >st;
        for(int i = 0;i<s.length();i++){
            if(st.empty()){
                st.push(make_pair(s[i],i));
            } else{
                pair<char,int> tp = (pair<char, int> &&) st.top();
                if(s[i]==')'&&tp.first=='('){
                    st.pop();
                    dp[i+1] = dp[i]+dp[tp.second]+1;
                    res = max(res,dp[i+1]);
                } else{
                    st.push(make_pair(s[i],i));
                }
            }



        }
        return 2*res;
    }
};