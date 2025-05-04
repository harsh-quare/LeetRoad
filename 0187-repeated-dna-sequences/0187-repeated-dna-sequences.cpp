class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        int i = 0;

        while(i <= n-10){
            string cur = s.substr(i, 10);
            mp[cur]++;
            i++;
        }

        vector<string> ans;
        for(auto [x, cnt]: mp){
            if(cnt > 1) ans.push_back(x);
        }

        return ans;
    }
};