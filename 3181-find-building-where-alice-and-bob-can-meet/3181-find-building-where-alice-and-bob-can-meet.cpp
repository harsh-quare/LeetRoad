class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> nextHigher(n, -1); //precomputed "next higher" indices
        stack<int> st;

        //step 1: precompute next higher building
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] >= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nextHigher[i] = st.top();
            }
            st.push(i);
        }

        // for(int i = 0; i < n; i++){
        //     cout << nextHigher[i] << " ";
        // }
        // cout << endl;

        vector<int> ans;
        for(auto& q : queries){
            int idA = q[0], idB = q[1];
            if(idA > idB) swap(idA, idB);

            //if heights[idA] < heights[idB], directly answer idB
            if(idA == idB || heights[idA] < heights[idB]){
                ans.push_back(idB);
            }
            // else heights[idA] >= heights[idB]
            // otherwise, find the leftmost taller building to the right of idB for idA
            else if(nextHigher[idA] == -1 || nextHigher[idB] == -1){
                ans.push_back(-1);
            }
            else{
                // heights[idA] >= heights[idB] still satisfies
                int idx = max(nextHigher[idA], nextHigher[idB]);
                if(heights[idx] > heights[idA] && heights[idx] > heights[idB]){
                    ans.push_back(idx);
                }
                else{
                    while(idx != -1 && (heights[idx] < heights[idA] || heights[idx] < heights[idB])){
                        idx = nextHigher[idx];
                    }
                    if(idx != -1 && heights[idx] > heights[idA] && heights[idx] > heights[idB]){
                        ans.push_back(idx);
                    }
                    else ans.push_back(-1);
                }                
            }
        }

        return ans;
    }
};

// 1. Key Observations


// Tallest Building Requirement:
// A valid building must be taller than both Alice's and Bob's buildings:
// heights[idx] > heights[idA] AND heights[idx] > heights[idB].

// Efficiency Using Precomputed Data:
// Instead of searching every building to the right of idA and idB one by one, we use the nextHigher array:
// nextHigher[i] gives the next taller building for the building at index i.

// Iterative Traversal:
// By following nextHigher indices, we skip over irrelevant buildings:
// Buildings shorter than either Alice's or Bob's building are ignored.
// This ensures we focus only on potentially valid candidates.


// 2. Why Start with max(nextHigher[idA], nextHigher[idB])?


// The nextHigher array tells us the closest taller building for each building.
// For indices idA and idB, the first possible candidate must be the maximum of their nextHigher values:
// max(nextHigher[idA], nextHigher[idB]).
// This ensures we start checking from the nearest taller building to both Alice and Bob, without missing any valid candidates.


// 3. Why Use a While Loop?


// After identifying the starting candidate (idx), we traverse through the nextHigher chain to find a valid building.

// Conditions in the While Loop:
// Terminate When idx == -1:
// If idx becomes -1, there are no more taller buildings to check. This happens when we reach the end of the nextHigher chain.
// Return -1 because no valid building was found.

// Skip Shorter Buildings:
// If heights[idx] <= heights[idA] or heights[idx] <= heights[idB], this building cannot be a valid answer.
// Update idx to nextHigher[idx] to move to the next candidate.

// Stop When Valid:
// If heights[idx] > heights[idA] and heights[idx] > heights[idB], this is the leftmost valid building.
// Append idx to the result and break.


// 4. Intuition Behind the Traversal


// Why Use nextHigher?
// Searching linearly from idA and idB is inefficient, as it may involve many irrelevant buildings.
// The nextHigher array skips over buildings that are guaranteed to be shorter, reducing unnecessary checks.

// Why Skip Shorter Buildings?
// A shorter building cannot satisfy the condition of being taller than both Alice's and Bob's buildings.
// Skipping them avoids redundant calculations.

// Why Check Both Conditions?
// The solution ensures the returned building is taller than both Alice's and Bob's buildings.
// This prevents returning a building that might only partially satisfy the requirements.


// 5. Final Steps


// Exit the Loop When Valid:
// As soon as we find a building that satisfies heights[idx] > heights[idA] && heights[idx] > heights[idB], we stop.
// This ensures the building is the leftmost taller building, as we traverse the nextHigher chain sequentially.

// Handle Edge Cases:
// If no building satisfies the condition, the loop exits with idx == -1, and we append -1 to the result.


// Why This Works
// This approach leverages the nextHigher array to efficiently skip invalid candidates and focus on potential taller buildings. By traversing through the nextHigher chain, we ensure:
// All shorter buildings are ignored.
// The first valid taller building encountered is the leftmost one.
// This is both efficient and logical, as it minimizes redundant checks and guarantees correctness. Let me know if you need further clarification!