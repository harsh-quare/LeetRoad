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
class FindElements {
private:
    void build(TreeNode* root){
        if(root == NULL) return ;

        if(root->left){
            root->left->val = root->val*2 + 1;
            mp[root->left->val] = true;
            build(root->left);
        }

        if(root->right){
            root->right->val = root->val*2 + 2;
            mp[root->right->val] = true;
            build(root->right);
        }
    }
public:
    unordered_map<int, bool> mp;

    FindElements(TreeNode* root) {
        root->val = 0;
        mp[0] = true;
        build(root);
    }
    
    bool find(int target) {
        return mp.find(target) != mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */