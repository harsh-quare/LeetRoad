class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans(queries.size());
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1]^arr[i];
        }

        for(int i = 0; i < queries.size(); i++){
            auto q = queries[i];
            int x = q[0];
            int y = q[1];

            if(x == 0){
                ans[i] = pref[y];
            }
            else{
                ans[i] = pref[y]^pref[x-1];
            }
        }

        return ans;
    }
};