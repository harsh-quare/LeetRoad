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
    int func(TreeNode* root, string& s, int& i, int d) {
        if (i >= s.size())  // Prevent out-of-bounds access
            return 0;
        
        int cnt = 0;
        while (i < s.size() && s[i] == '-') {
            i++;
            cnt++;
        }

        if (i >= s.size())  // Prevent out-of-bounds access
            return cnt;

        int ind = i;  // Temporary index variable
        int val = 0;
        while (ind < s.size() && isdigit(s[ind])) {  // Extract the full number
            val = val * 10 + (s[ind] - '0');
            ind++;
        }

        if (d + 1 == cnt) {
            root->left = new TreeNode(val);
            i = ind;  // Update i only when assigning a node
            cnt = func(root->left, s, i, d + 1);
        }

        if (d + 1 == cnt) {
            ind = i;  // Reset ind to current i
            val = 0;
            while (ind < s.size() && isdigit(s[ind])) {  // Extract the full number
                val = val * 10 + (s[ind] - '0');
                ind++;
            }
            root->right = new TreeNode(val);
            i = ind;  // Update i only when assigning a node
            cnt = func(root->right, s, i, d + 1);
        }

        return cnt;
    }

    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        int ind = i;  // Temporary index variable
        int val = 0;
        
        while (ind < s.size() && isdigit(s[ind])) {  // Extract the root value
            val = val * 10 + (s[ind] - '0');
            ind++;
        }

        TreeNode* root = new TreeNode(val);
        i = ind;  // Update i only after extracting the root value
        func(root, s, i, 0);
        return root;
    }
};