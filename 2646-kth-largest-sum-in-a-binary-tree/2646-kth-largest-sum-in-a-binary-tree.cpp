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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //Level order traversal to mandatory h
        //BFS

        //kth largest chahiye to min heap lelo and uska size hamesha k maintain krke chalo
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        int levels = 0;

        while(!q.empty()){
            int sz = q.size();
            long long levelSum = 0;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            //current level is traversed
            pq.push(levelSum);
            if(pq.size() > k) pq.pop();

            levels++;
        }

        if(levels < k) return -1;
        else return pq.top();
    }
};