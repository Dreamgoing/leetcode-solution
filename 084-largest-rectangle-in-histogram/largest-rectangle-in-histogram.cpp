class Solution {
public:

    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            if (st.empty() || st.top() <= heights[i]) {
                st.push(heights[i]);
            } else {
                int count = 0;
                while (!st.empty() && st.top() > heights[i]) {
                    count++;
                    res = max(res, st.top() * count);
                    st.pop();
                }
                while (count--)
                    st.push(heights[i]);

                st.push(heights[i]);
            }
        }
        int count = 1;
        while (!st.empty()){
            res = max(res, st.top()*count);
            st.pop();
            count++;
        }
        return res;
    }
};