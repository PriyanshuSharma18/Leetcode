
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const static int LEFT = 0,RIGHT = 1;
    int ans = 0;
    // left direction = 0, right direction = 1;
    void dfs(TreeNode *root,int prevDirect,int zigzag){
        if(root==nullptr) return;
        ans = max(ans,zigzag);
        if(prevDirect==LEFT){
            dfs(root->left,LEFT,1);
            dfs(root->right,RIGHT,zigzag+1);
        }
        else if(prevDirect==RIGHT){
            dfs(root->left,LEFT,zigzag+1);
            dfs(root->right,RIGHT,1);
        }
        else{
            dfs(root->left,LEFT,zigzag+1);
            dfs(root->right,RIGHT,zigzag+1);
        }
    }
    int longestZigZag(TreeNode* root){
        ans = 0;
        dfs(root,-1,0);
        return ans;
    }
};