/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preS, int preE, vector<int>& postorder, int postS, int postE, map<int, int>& post) {
        if (preS > preE || postS > postE) return NULL;
        
        TreeNode* node = new TreeNode(preorder[preS]);
        
        // If there is only one node, return it
        if (preS == preE) return node;

        // Find the left child in the postorder array
        int leftChild = preorder[preS + 1];
        int leftChildIndex = post[leftChild];

        // Calculate the size of the left subtree
        int leftSize = leftChildIndex - postS + 1;

        // Recursively build the left and right subtrees
        node->left = build(preorder, preS + 1, preS + leftSize, postorder, postS, leftChildIndex, post);
        node->right = build(preorder, preS + leftSize + 1, preE, postorder, leftChildIndex + 1, postE - 1, post);
        
        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int, int> post;
        for (int i = 0; i < postorder.size(); i++) {
            post[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, post);
    }
};