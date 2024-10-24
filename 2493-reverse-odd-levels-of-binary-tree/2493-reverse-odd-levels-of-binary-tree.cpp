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
    void reverse(TreeNode* lt, TreeNode* rt, int lvl){
        if(!lt || !rt) return ;
        
        if(lvl % 2 != 0){
            swap(lt->val, rt->val);
        }

        reverse(lt->left, rt->right, lvl+1);
        reverse(lt->right, rt->left, lvl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        reverse(root->left, root->right, 1);
        return root;
    }
};