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
    int level[1000001];  //storing level of each node
    int NodeHt[100001];  //storing height of each node from below(number of nodes below this node) : height = # of nodes-1
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int lvl){
        if(root == NULL) return 0;

        level[root->val] = lvl;
        NodeHt[root->val] = max(findHeight(root->left, lvl+1), findHeight(root->right, lvl+1)) + 1;

        if(NodeHt[root->val] > levelMaxHt[lvl]){
            levelSecondMaxHt[lvl] = levelMaxHt[lvl];
            levelMaxHt[lvl]= NodeHt[root->val];
        }
        else if(levelSecondMaxHt[lvl] < NodeHt[root->val]){
            levelSecondMaxHt[lvl] = NodeHt[root->val];
        }

        return NodeHt[root->val];

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        findHeight(root, 0);  //populate krke le aao saare precomputing data structures ko

        for(auto& node: queries){
            //node: that we will be deleting
            int L = level[node];

            // ans = L + H - 1 :: But check if the node that we are deleting is itself the guy with most height in its level, if yes then we need to get the second maxHt guy from this level
            // H-1 bcs we calculated height as number of nodes, and we need to calculate it in terms of edges below this node, so number of edges below will be (number of nodes below - 1)

            int H = (NodeHt[node] == levelMaxHt[L]) ? levelSecondMaxHt[L] : levelMaxHt[L];

            int tempRes = L + H - 1;

            ans.push_back(tempRes);
        }

        return ans;
    }
};