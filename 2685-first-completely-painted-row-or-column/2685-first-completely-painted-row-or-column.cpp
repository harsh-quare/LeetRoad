class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowP(n, 0);
        vector<int> colP(m, 0);

        vector<pair<int, int>> vp(m*n+1); // values are between [1,m*n], so we use 1-based indexing

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = mat[i][j];
                vp[val] = {i, j};
            }
        }

        for(int k = 0; k < arr.size(); k++){
            int val = arr[k];

            int x = vp[val].first;
            int y = vp[val].second;

            rowP[x]++;
            colP[y]++;

            if(rowP[x] >= m || colP[y] >= n) return k;  // ek row tab bharegi, jab usme number of columns jitne bnde honge and vice versa
        }

        return m*n-1;
    }   
};