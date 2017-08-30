class Solution {
public:
    const int inf = 0x3f3f3f3f;

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        auto n = wordList.size() + 1;
        vector<string> tmp = wordList;
        tmp.push_back(beginWord);
        vector<vector<int>> g(n, vector<int>{});
        if (beginWord == endWord) {
            return true;
        }
        int t = -1;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == endWord) {
                t = i;
                break;
            }
        }
        if (t == -1) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (can_trans(tmp[i], tmp[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        auto res = dijstra(g, n - 1, t);
        if(res!=inf){
            return res+1;
        } else{
            return 0;
        }

    }

    int dijstra(const vector<vector<int>> &g, int s, int t) {
        vector<int> d(g.size(), inf);
        vector<bool> vis(g.size(), 0);
        d[s] = 0;
        for (int i = 0; i < g.size(); i++) {
            int u = min_dis(d, vis);
            vis[u] = true;
            for (int j = 0; j < g[u].size(); j++) {
                auto nxt = g[u][j];
                if (!vis[nxt] && d[u] != inf && d[u] + 1 < d[nxt]) {
                    d[nxt] = d[u] + 1;
                }
            }
        }
        return d[t];
    }

    int min_dis(const vector<int> &d, const vector<bool> &vis) {
        int min_num = inf, min_idx = -1;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == false && d[i] <= min_num) {
                min_num = d[i];
                min_idx = i;
            }
        }
        return min_idx;
    }


    bool can_trans(const string &a, const string &b) {
        int num = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                num++;
            }
        }
        return num == 1;
    }

};