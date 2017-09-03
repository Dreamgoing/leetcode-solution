class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> op;
        string res;
        string cur;
        for (int i = 0; i < s.length(); i++) {
            auto it = s[i];
            if (isdigit(it)) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                i--;
                op.push(num);
            } else if (it != ']') {
                string tmp(1,it);
                st.push(tmp);
            } else {
                cur.clear();
                while (st.top() != "[" && !st.empty()) {
                    cur += st.top();
                    st.pop();
                }

                st.pop();
                auto tmp = duplicate(cur, op.top());
                st.push(tmp);
                op.pop();
            }
        }
        cur.clear();
        while (!st.empty()) {
            cur += st.top();
            st.pop();
        }
        reverse(cur.begin(), cur.end());
        return res + cur;
    }

    string duplicate(string str, int num) {
        string res;
        for (int i = 0; i < num; i++) {
            res += str;
        }
        return res;
    }
};