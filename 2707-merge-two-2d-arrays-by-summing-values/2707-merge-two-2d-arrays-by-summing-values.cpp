class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxId = max(nums1[n-1][0], nums2[m-1][0]);
        vector<int> ids(maxId + 1, -1);

        for(int i = 0; i < n; i++){
            int id = nums1[i][0];
            int val = nums1[i][1];

            ids[id] = val;
        }

        for(int i = 0; i < m; i++){
            int id = nums2[i][0];
            int val = nums2[i][1];

            if(ids[id] == -1){
                ids[id] = val;
            }
            else{
                ids[id] += val;
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < ids.size(); i++){
            if(ids[i] != -1){
                ans.push_back({i, ids[i]});
            }
        }

        return ans;
    }
};