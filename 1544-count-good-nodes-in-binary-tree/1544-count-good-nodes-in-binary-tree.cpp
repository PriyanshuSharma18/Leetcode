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
    int nodecount(TreeNode* node, int highest){
        if(node==NULL)return 0;
        if(highest>node->val){
            return nodecount(node->right,highest)+nodecount(node->left,highest);
        }
        return 1+nodecount(node->right,node->val)+nodecount(node->left,node->val);
    }
    int goodNodes(TreeNode* root) {
        return nodecount(root,INT_MIN);
    }
};