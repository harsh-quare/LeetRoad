class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowP(n, 0);
        vector<int> colP(m, 0);

        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        for(int k = 0; k < arr.size(); k++){
            int val = arr[k];

            int x = mp[val].first;
            int y = mp[val].second;

            rowP[x]++;
            colP[y]++;

            if(rowP[x] >= m || colP[y] >= n) return k;  // ek row tab bharegi, jab usme number of columns jitne bnde honge and vice versa
        }

        return m*n-1;
    }   
};