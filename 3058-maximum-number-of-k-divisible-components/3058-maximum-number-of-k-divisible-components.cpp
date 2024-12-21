class Solution {
public:
    vector<vector<int>> g;
    pair<int, int> dfs(int pre, int cur, vector<int> &values, int k) {
        pair<int, int> res = {values[cur] % k, 0};
        for (auto &x: g[cur]) {
            if (x == pre) continue;
            auto [cnt, pairs] = dfs(cur, x, values, k);
            res.first = (res.first + cnt) % k;
            res.second += pairs;
        }
        if (res.first == 0) res.second += 1;
        return res;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.resize(n);
        for (auto &x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        return dfs(-1, 0, values, k).second;
    }
};