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

// Example
// Tree:
// markdown
//         1
//       /   \
//     45     15
//    /  \   /  \
//   20  39 46  25
//  /
// 27
// Level-by-Level Values:
// Level 1: [1] (No swaps needed)
// Level 2: [45, 15]
// Level 3: [20, 39, 46, 25]
// Level 4: [27] (No swaps needed)
// We'll focus on Level 3: [20, 39, 46, 25].

// Initial Step:
// Extract the values with their original indices:
// nextLvl = [(20, 0), (39, 1), (46, 2), (25, 3)]

// Sort by values (retain indices):
// sortedLvl = [(20, 0), (25, 3), (39, 1), (46, 2)]

// Track Original and Sorted Indices:

// Original: 20 -> 0, 39 -> 1, 46 -> 2, 25 -> 3
// Sorted: 20 -> 0, 25 -> 3, 39 -> 1, 46 -> 2
// Identify Cycles for Sorting:

// A "cycle" forms when a value at index i is not at its correct position in the sorted array.
// Cycle Detection Steps
// Start:
// Initialize visited = [false, false, false, false].
// Iterate through each element:
// Check Element at Index 0:

// Current: sortedLvl[0] = (20, 0)
// Position matches (sortedLvl[0].second == nextLvl[0].second).
// No swap needed. Mark as visited: visited[0] = true.
// Check Element at Index 1:

// Current: sortedLvl[1] = (25, 3)
// sortedLvl[1].second != nextLvl[1].second (3 != 1).
// Cycle detected.
// Follow the Cycle:
// Start at index 1: (25, 3) (sorted index is 3).
// Move to index 3: (46, 2) (sorted index is 2).
// Move to index 2: (39, 1) (sorted index is 1).
// Return to index 1 (cycle complete).
// Cycle Size = 3 → Cycle Size - 1 = 2 swaps.

// Check Element at Index 2:

// Already visited during the cycle. Skip.
// Check Element at Index 3:

// Already visited during the cycle. Skip.
// Total Swaps for This Level:
// 2 swaps.
// Why Does Cycle Detection Work?
// Cycle detection works because:

// Each misplaced element in a cycle needs to be moved to its correct position.
// In a cycle of size k, exactly k-1 swaps are required to sort all elements.
// Final Output
// For the entire tree:

// Level 1: 0 swaps
// Level 2: 1 swap
// Level 3: 2 swaps
// Level 4: 0 swaps
// Total = 0 + 1 + 2 + 0 = 3 swaps.