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
    int minimumOperations(TreeNode* root) {
        // For each level, check how many nodes are not at their correct positions
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<pair<int, int>> nextLvl;
            int i = 0;  //position
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) {
                    nextLvl.push_back({node->left->val, i++});
                    q.push(node->left);
                }
                if(node->right) {
                    nextLvl.push_back({node->right->val, i++});
                    q.push(node->right);
                }
            }
            //calculate the minimum swaps needed for the current level
            if(!nextLvl.empty()){
                //sort by value while keeping track of original indices
                vector<pair<int, int>> sortedLvl = nextLvl;
                sort(sortedLvl.begin(), sortedLvl.end());

                //map original index to sorted position
                vector<bool> visited(nextLvl.size(), false);
                for(int j = 0; j < nextLvl.size(); j++){
                    if(visited[j] || sortedLvl[j].second == nextLvl[j].second) 
                        continue;

                    //detect cycles in the graph
                    int cycleSize = 0;
                    int x = j;

                    while(!visited[x]){
                        visited[x] = true;
                        x = sortedLvl[x].second;
                        cycleSize++;
                    }

                    if(cycleSize > 1) ans += (cycleSize - 1);
                }
            }
        }

        return ans;
    }
};