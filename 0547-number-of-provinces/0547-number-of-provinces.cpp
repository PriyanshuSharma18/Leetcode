class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                ++groups;
            }
        }
        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
};