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
        TreeNode* rt = root;
        q.push(rt);
        vector<int> sums; //saare levels ke level sum ko store krlo

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

                if(node->right) {
                    q.push(node->right);
                }
            }

            sums.push_back(levelSum);
        }

        //ab fir se traverse kro and tree ko modify kro
        TreeNode* r = root;
        queue<pair<TreeNode*, int>> qq;
        qq.push({r, root->val});
        int i = 0;
        while(!qq.empty()){
            int sz= qq.size();

            while(sz--){
                TreeNode* node = qq.front().first;
                int childSum = qq.front().second;
                qq.pop();

                int curChSum = 0;

                if(i <= 1) node->val = 0;
                else node->val = sums[i] - childSum;

                if(node->left){
                    curChSum += node->left->val;
                }
                if(node->right){
                    curChSum += node->right->val;
                }

                if(node->left){
                    qq.push({node->left, curChSum});
                }
                if(node->right){
                    qq.push({node->right, curChSum});
                }

            }
            i++; //next level
        }

        return root;
    }
};