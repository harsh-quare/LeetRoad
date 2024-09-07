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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL || head == NULL) return false;
        if(root->val == head->val){
            if(dfs(root, head)) return true;
        }

        bool l = isSubPath(head, root->left);
        bool r = isSubPath(head, root->right);
        return l || r;
    }

    bool dfs(TreeNode* &node, ListNode* head){
        if(node == NULL || head == NULL) return false;
        if(node->val != head->val) return false;

        if(head->next == NULL && head->val == node->val) return true;

        bool l = dfs(node->left, head->next);
        bool r = dfs(node->right, head->next);
        
        return l || r;
    }
};