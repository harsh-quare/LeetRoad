class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());

        vector<string> ans;
        
        int cnt = n;
        vector<bool> ready(n, false);
        
        while(cnt--){
            for(int i = 0; i < n; i++){
                if(ready[i] == true){
                    continue;
                }

                bool isPossible = true;
                for(int j = 0; j < ingredients[i].size(); j++){
                    string ing = ingredients[i][j];
                    if(st.find(ing) == st.end()){
                        isPossible = false;
                        break;
                    }
                }

                if(isPossible == true){
                    ready[i] = true;
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                }
            }
        }

        return ans;
    }
};

// The worst case can be that, the last recipe can be made by given supply, which will be done in first iteration itself
// But the second last recipe can be made by last recipe, and for that we need another iteration
// And so on, means the thir last needs second last as recipe

// So, in the worst case, we would need to iterate for the same process for n times