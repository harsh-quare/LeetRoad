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
    int maxLevelSum(TreeNode* root) {
        // BFS => Queue
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        int curLevel = 1;
        int ans = 1;
        int maximalSum = root->val;

        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            int curLevelSum = 0;

            while(size--){
                TreeNode* curNode = bfsQueue.front();
                bfsQueue.pop();

                curLevelSum += curNode->val;

                if(curNode->left) bfsQueue.push(curNode->left);
                if(curNode->right) bfsQueue.push(curNode->right);
            }

            if(curLevelSum > maximalSum){
                maximalSum = curLevelSum;
                ans = curLevel;
            }

            curLevel++;
        }

        return ans;
    }
};