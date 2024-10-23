class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> levelSum;
        q.push(root);
        int n,sum,currSum;
        
        while(!q.empty()){
            n = q.size();
            sum = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            levelSum.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int level = 0;
        while(!q.empty()){
            n = q.size();
            sum = level+1 < levelSum.size() ? levelSum[level+1] : 0;
            while(n--){
                currSum = 0;
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    currSum += node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    currSum += node->right->val;
                    q.push(node->right);
                }
                if(node->left)  node->left->val  = sum - currSum;
                if(node->right) node->right->val = sum - currSum;
            }
            level++;
        }

        return root;
    }
};