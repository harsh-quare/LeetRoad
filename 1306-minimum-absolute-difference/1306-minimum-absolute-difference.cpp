class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minDiff = arr[n-1] - arr[0];

        for(int i = 0; i < n-1; i++){
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n-1; i++){
            if(arr[i+1] - arr[i] == minDiff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};