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
    TreeNode* reverseOddLevels(TreeNode* root) {
        //two pass solution
        unordered_map<int, vector<int>> mp;
        int l = 0;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> real;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> nxtLvl;
            int ptr = real.size()-1;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(l % 2 != 0){
                    node->val = real[ptr];
                    ptr--;
                }

                if(node->left){
                    if(l % 2 == 0){
                        nxtLvl.push_back(node->left->val);
                    }
                    q.push(node->left);
                }
                if(node->right){
                    if(l % 2 == 0){
                        nxtLvl.push_back(node->right->val);
                    }
                    q.push(node->right);
                }
            }
            real = nxtLvl;
            l++;
        }

        return root;
    }
};