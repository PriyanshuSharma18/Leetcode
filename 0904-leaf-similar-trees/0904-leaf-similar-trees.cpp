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
class leafIterator {
    // stack for recursion enumeration
    stack<TreeNode*> st;
public:
    // constructor intialises the stack with the root node
    leafIterator(TreeNode* root) {
        st.push(root);
    }
    // provides the next leaf node if not present returns -1
    int nextLeaf(){
        if(st.empty()) return -1;
        while(st.empty() || !isLeaf(st.top())){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right != NULL)
                st.push(curr->right);
            if(curr->left != NULL)
                st.push(curr->left);
        }
        int ans = st.top()->val;
        st.pop();
        return ans;
    }
private:
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leafIterator* It1 = new leafIterator(root1);
        leafIterator* It2 = new leafIterator(root2);
        int leaf1 = It1->nextLeaf(), leaf2 = It2->nextLeaf(); 
        while(leaf1 != -1 && leaf2 != -1){
            if(leaf1 != leaf2) return false;
            leaf1 = It1->nextLeaf();
            leaf2 = It2->nextLeaf();
        }
        return leaf1 == leaf2;
    }
};