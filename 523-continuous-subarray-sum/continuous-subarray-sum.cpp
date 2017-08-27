class Solution {
public:

    bool checkSubarraySum(vector<int> &nums, int k) {
        vector<int> sum(nums.size() + 1, 0);
        unordered_map<int, int> vis;
        k = abs(k);
        for (int i = 0; i < nums.size(); i++) {
            if (k == 0) {
                sum[i + 1] = (sum[i] + nums[i]);
            } else {
                sum[i + 1] = (sum[i] + nums[i]) % k;
            }

        }
        for (int i = 1; i < sum.size(); i++) {
            if (i != 1 && sum[i] == 0) {
                return true;
            }
            if ((vis[sum[i]] != 0) && vis[sum[i]] != i - 1) {
                return true;
            }
            vis[sum[i]] = vis[sum[i]] == 0 ? i : min(vis[sum[i]], i);
        }
        return false;
    }
};