class Solution {
public:
    const int inf = 0x3f3f3f3f;
    vector<pair<int, int> > width;

    int widthOfBinaryTree(TreeNode *root) {
        dfs(root, 1, 1);
        int res = 0;
        for (int i = 0; i < width.size(); i++) {
            if (is_valid(i, width[i].first) &&
                is_valid(i, width[i].second) &&
                width[i].first != inf &&
                width[i].second != inf) {
                res = max(res, width[i].second - width[i].first + 1);
            }
        }
        return res;
    }

    bool is_valid(int i, int x) {
        return ((1 << i) - 1) < x && x <= ((1 << (i + 1)) - 1);
    }

    void dfs(TreeNode *node, int deep, int pos) {
        if (node == nullptr) {
            return;
        }
        if (width.size() < deep) {
            width.emplace_back(inf, -inf);
        }
        width[deep - 1].first = min(pos, width[deep - 1].first);
        width[deep - 1].second = max(pos, width[deep - 1].second);
        dfs(node->left, deep + 1, 2 * pos);
        dfs(node->right, deep + 1, 2 * pos + 1);
    }

};