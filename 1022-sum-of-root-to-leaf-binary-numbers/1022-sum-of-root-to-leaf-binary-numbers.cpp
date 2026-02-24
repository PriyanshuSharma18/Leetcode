using info=pair<TreeNode*, int>; //(node, x)
info q[1000];
class Solution {
public:
    static int sumRootToLeaf(TreeNode* root) {
        int back=0, front=0, sum=0;
        q[back++]={root, 0};// push
        while(front<back){
            auto [node, x]=q[front++];// pop
            x=(x<<1)+node->val;
            if (node->left==node->right) {// leaf node
                sum+=x;
                continue;
            }
            if (node->left)  q[back++]={node->left, x};// push
            if (node->right) q[back++]={node->right, x};// push
        }
        return sum;
    }
};