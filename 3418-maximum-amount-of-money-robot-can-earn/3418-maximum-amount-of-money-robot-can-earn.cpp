int dp[500][500][3]; // DP array 
class Solution {
    static int f(int i, int j, int k, vector<vector<int>>& coins) {
        if (i==0 && j==0) {// // Base case 
            if (k>0) return max(0, coins[0][0]); 
            return coins[0][0]; 
        }
        if (i<0 || j<0 || k<0) return -1e9;

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
        const int x=coins[i][j];
        int ans=x+max(f(i-1, j, k, coins), f(i, j-1, k, coins));
        // If x<0, k>0 neutralize robber once
        if (x<0 && k>0) 
            ans=max({ans, f(i-1, j, k-1, coins), f(i, j-1, k-1, coins)});
        
        return dp[i][j][k]=ans;
    }

public:
    static int maximumAmount(vector<vector<int>>& coins) {
        const int r=coins.size(), c=coins[0].size();
        // Initialize DP with INT_MIN
        fill(&dp[0][0][0], &dp[0][0][0]+500*500*3, INT_MIN);
        return f(r-1, c-1, 2, coins);
    }
};
