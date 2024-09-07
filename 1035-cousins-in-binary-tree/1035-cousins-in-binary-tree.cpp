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
    bool isCousins(TreeNode* root, int x, int y) {
        int par1 = -1, par2 = -1;
        int l1 = -1, l2 = -1;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node= q.front();
                q.pop();

                if(node->val == x && l1 == -1){
                    l1 = level;
                }
                if(node->val == y && l2 == -1){
                    l2 = level;
                }

                if(node->left){
                    if(node->left->val == x) par1 = node->val;
                    if(node->left->val == y) par2 = node->val;
                    q.push(node->left);
                }

                if(node->right){
                    if(node->right->val == x) par1 = node->val;
                    if(node->right->val == y) par2 = node->val;
                    q.push(node->right);
                }
            }
            level++;
 
            if(l1 != -1 && l2 != -1) break;
        }

        if(l1 <= 1 || l2 <= 1) return false;
        if(l1 != l2 || par1 == par2) return false;
        return true;
    }
};