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
    int maxLevelSum(TreeNode* root) {
        int x = -1;
        //level order traversal krna padinga
        int maxSum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int sz = q.size();
            int levelSum = 0;
            while(sz--){
                TreeNode* node= q.front();
                q.pop();
                levelSum += node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right) q.push(node->right);
            }

            if(levelSum > maxSum){
                maxSum = levelSum;
                x = level;
            }

            level++;
        }

        return x;
    }
};