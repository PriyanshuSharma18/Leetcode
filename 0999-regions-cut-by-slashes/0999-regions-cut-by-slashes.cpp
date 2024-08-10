class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&vec, vector<vector<int>>&vis, int del_row[], int del_col[], int n){
        vis[row][col] = 1;
        
        for(int i = 0 ; i < 4; i++){
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];
            if(nrow >= 0 && nrow < n*3 && ncol >= 0 && ncol < n*3 && vec[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                dfs(nrow, ncol, vec, vis, del_row, del_col, n);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>vec(n * 3, vector<int>(n * 3));
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '/'){
                    vec[i * 3][j * 3 + 2] = vec[i * 3 + 1][j * 3  + 1] = vec[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    vec[i * 3][j * 3] = vec[i * 3 + 1][j * 3 + 1] = vec[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }


        vector<vector<int>>vis(n * 3, vector<int>(n * 3, 0));

        int count = 0;
        int del_row[4] = {0, -1, 0, +1};
        int del_col[4] = {-1, 0, +1, 0};
        for(int i = 0; i < n*3; i++){
            for(int j = 0; j < n*3 ; j++){
                if(!vis[i][j] && vec[i][j] == 0){
                    count = count + 1;
                    dfs(i, j, vec, vis, del_row, del_col, n);
                }
            }
        }
        return count;
    }
};