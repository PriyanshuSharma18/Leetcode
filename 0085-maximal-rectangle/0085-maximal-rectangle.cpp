class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));

        }
        return maxArea;
    }
private: 
    int largestRectangleArea(vector<int>& heights){
        // with single pass monotonic stack
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; ++i){
            int h = (i == n) ? 0 : heights[i]; // 0 is sentinel value
            while(!st.empty() && h < heights[st.top()]){
                int curHeight = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, curHeight * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};