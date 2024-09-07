/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void solve(TreeNode* &root, vector<TreeNode*>& v, int val){
        if(root == NULL) return ;

        //LNR
        solve(root->left, v, val);

        if(root->val == val){
            v.push_back(root);
        }

        solve(root->right, v, val);
    }

    bool dfs(TreeNode* &node, ListNode* head){
        if(node == NULL || head == NULL) return false;
        if(node->val != head->val) return false;

        if(head->next == NULL && head->val == node->val) return true;

        bool l = dfs(node->left, head->next);
        bool r = dfs(node->right, head->next);
        
        return l | r;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> v;
        solve(root, v, head->val);

        if(v.size() == 0) return false;

        for(int i = 0; i<v.size(); i++){
            TreeNode* node = v[i];
            cout << node->val << endl;
            if(dfs(node, head)){
                return true;
            }
        }
        return false;
    }
};