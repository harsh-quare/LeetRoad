class Solution {
public:
    bool isValid(vector<vector<int>>& pref, int mid, int threshold){
        int n = pref.size();
        int m = pref[0].size();

        for(int i = mid-1; i < n; i++){
            for(int j = mid-1; j < m; j++){
                int x1 = i-mid+1;
                int y1 = j-mid+1;

                int sum = pref[i][j] - (x1 > 0 ? pref[x1-1][j] : 0) - (y1 > 0 ? pref[i][y1-1] : 0) + (x1 > 0 && y1 > 0 ? pref[x1-1][y1-1] : 0);

                if(sum <= threshold) return true;
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref = mat;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                pref[i][j] += pref[i][j-1];
            }
        }

        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                pref[i][j] += pref[i-1][j];
            }
        }

        int low = 1, high = min(n,m);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(isValid(pref, mid, threshold)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};

// low = 1
// high = min(n,m)