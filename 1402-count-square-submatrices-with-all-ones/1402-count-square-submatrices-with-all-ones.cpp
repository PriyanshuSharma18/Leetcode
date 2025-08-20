class Solution {
public:
    static int countSquares(vector<vector<int>>& mx) {
        const int m = mx.size();
        const int n = mx[0].size();
        int count = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (mx[i][j] == 1) {
                    mx[i][j] = 1 + min(mx[i - 1][j - 1], min(mx[i - 1][j], mx[i][j - 1]));
                    count += mx[i][j];
                }
            }
        }
        for (int j = 0; j < n; ++j) count += mx[0][j];
        for (int i = 1; i < m; ++i) count += mx[i][0];
        return count;
    }
};