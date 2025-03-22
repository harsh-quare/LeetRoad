class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Using Kahn's algorithm

        int n = recipes.size();
        unordered_set<string> supp(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>> adj;  // ingredient(which is a recipe too) -> recipe_idx(that it can be used in making)

        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(string& ing: ingredients[i]){
                if(supp.find(ing) == supp.end()){
                    adj[ing].push_back(i);  // this ingredient is missing in ith recipe
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<string> ans;
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            string rec = recipes[idx];
            ans.push_back(rec);

            for(int& id: adj[rec]){
                indegree[id]--;
                if(indegree[id] == 0){
                    q.push(id);
                }
            }
        }

        return ans;
    }
};