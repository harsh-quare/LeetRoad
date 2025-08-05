class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        vector<bool> vis(n, 0);

        for(int i = 0; i < n; i++){
            int f = fruits[i];
            bool allotted = false;

            for(int j = 0; j < n; j++){
                if(!vis[j] && baskets[j] >= f){
                    vis[j] = 1;  // mark used
                    allotted = true;
                    break;
                }
            }

            if(!allotted) ans++;
        }

        return ans;
    }
};