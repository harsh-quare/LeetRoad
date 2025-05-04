class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;

        for(int i = 0; i < dominoes.size(); i++){
            sort(dominoes[i].begin(), dominoes[i].end());
            mp[dominoes[i]]++;
        }

        int cnt = 0;
        for(auto [v, c]: mp){
            cnt += c*(c-1)/2;
        }

        return cnt;
    }
};