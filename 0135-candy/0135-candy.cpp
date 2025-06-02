class Solution {
public:
    int candy(vector<int>& ratings) {
        // double sweep is making sense to me
        int n = ratings.size();
        vector<int> help(n, 1);  // given at least 1 to all

        // left to right
        for(int i = 1; i <= n-1; i++){
            // increment rating only if it's greater than previous one
            if(ratings[i] > ratings[i-1]){
                help[i] = max(help[i], help[i-1] + 1);
            }
            // else the rating will remain the same, as we are not breaking the conditions considering only left nbr
        }

        // right to left
        for(int i = n-2; i >= 0; i--){
            // increment rating only if it's greater than previous one
            if(ratings[i] > ratings[i+1]){
                help[i] = max(help[i], help[i+1] + 1);
            }
            // else the rating will remain the same, as we are not breaking the conditions considering only right nbr
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(help[i], help[i]);
        }

        return ans;
    }
};