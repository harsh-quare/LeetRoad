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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2)) return false;
        if(root1->val != root2->val) return false;

        //Recursively ye Check kr lo ki ya to (r1 ka left and r2 ka left same ho && r1 ka right and r2 ka right same ho) ya fir (r1 ka left, r2 ke right ke same ho && r2 ka right r1 ke left se same ho)
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || 
                (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};