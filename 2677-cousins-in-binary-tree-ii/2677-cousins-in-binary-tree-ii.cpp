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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);  
        int lvlSum = root->val; //levelSum

        while(!q.empty()){
            int sz = q.size();
            int childSum = 0;

            while(sz--){
                TreeNode* node= q.front();
                q.pop();

                node->val = lvlSum - node->val;

                if(node->left){
                    q.push(node->left);
                    childSum += node->left->val;
                }

                if(node->right) {
                    q.push(node->right);
                    childSum += node->right->val; 
                }

                if(node->left != NULL && node->right != NULL){
                    int tempSum = node->left->val + node->right->val;
                    node->left->val = tempSum;
                    node->right->val = tempSum;
                }
            }

            lvlSum = childSum;
        }

        return root;
    }
};