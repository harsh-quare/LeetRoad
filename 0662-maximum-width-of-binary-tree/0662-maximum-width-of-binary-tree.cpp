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
    int widthOfBinaryTree(TreeNode* root) {
        // we need to check for each level, so use BFS
        // We need two informations about each node, first the node pointer itself and another the index that we'll represent it with

        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});

        int ans = INT_MIN;
        while(!q.empty()){
            // in each level, check which is the larget index you got, and which is the minimum index
            int sz = q.size();
            unsigned long long right_most;
            unsigned long long left_most;
            for(int i = 0; i < sz; i++){
                pair<unsigned long long, TreeNode*> p = q.front();
                q.pop();

                unsigned long long idx = p.first;
                TreeNode* node = p.second;

                if(i == 0) left_most = idx;
                if(i == sz-1) right_most = idx;

                // cout << idx << ": " << node->val << endl;

                if(node->left){
                    q.push({2*idx+1, node->left});
                }
                if(node->right){
                    q.push({2*idx+2, node->right});
                }
            }

            // cout << left_most << " " << right_most << endl;

            // for this level, update the result if better
            int wid = right_most - left_most + 1;
            ans = max(ans, wid);
        }

        return ans;
    }
};