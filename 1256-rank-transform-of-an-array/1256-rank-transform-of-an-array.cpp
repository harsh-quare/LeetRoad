class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> help;
        for(int i = 0; i < n; i++){
            help.push_back({arr[i], i});
        }
        sort(help.begin(), help.end());
        
        vector<int> ans(n);
        if(n == 0) return ans;
        ans[help[0].second] = 1;
        int prevVal = help[0].first;
        int prevRank = 1;
        
        for(int i = 1; i < n; i++){
            int val = help[i].first;
            int idx = help[i].second;

            if(val == prevVal){
                ans[idx] = prevRank;
            }
            else{
                ans[idx] = prevRank + 1;
                prevVal = val;
                prevRank = ans[idx];  // or prevRank++
            }
        }
        return ans;
    }
};