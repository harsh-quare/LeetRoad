class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;

        for(int i = 0; i < dominoes.size(); i++){
            if(dominoes[i][1] < dominoes[i][0]) swap(dominoes[i][0], dominoes[i][1]);
            mp[dominoes[i]]++;
        }

        int cnt = 0;
        for(auto [v, c]: mp){
            cnt += c*(c-1)/2;
        }

        return cnt;
    }
};