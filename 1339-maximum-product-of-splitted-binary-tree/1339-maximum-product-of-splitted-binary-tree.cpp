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
private: 
    const int mod = 1e9 + 7;
    long long getTreeSum(TreeNode* root){
        if(!root) return 0;

        long long sum = root->val;

        sum += getTreeSum(root->left);
        sum += getTreeSum(root->right);

        return sum;
    }
    long long getMaxProd(TreeNode* root, int treeSum, long long& ans){
        if(!root) return 0;

        long long curSum = 0;

        curSum += getMaxProd(root->left, treeSum, ans);
        curSum += getMaxProd(root->right, treeSum, ans);
        curSum += root->val;

        long long otherSum = treeSum - curSum;
        ans = max(ans, curSum*otherSum);

        return curSum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long treeSum = getTreeSum(root);

        long long ans = 1;

        getMaxProd(root, treeSum, ans);
        return ans % mod;
    }
};

// step-1: find the sum of entire tree
// step-2: start the post order traversal and keep the track of sum of current subtree
// step-3: subtree1Sum = current_subtree_sum, subtree2Sum = treeSum - subtree1Sum
// step-4: ans = max(ans, subtree1Sum * subtree2Sum)