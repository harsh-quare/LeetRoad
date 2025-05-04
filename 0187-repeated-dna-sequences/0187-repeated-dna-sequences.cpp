class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n < 10) return {};

        unordered_map<string, int> mp;
        vector<string> ans;
        int i = 0;

        while(i <= n-10){
            string cur = s.substr(i, 10);
            if(mp.count(cur)){
                if(mp[cur] == 1) ans.push_back(cur);  // only add it to answer if encountered second time, after that it will be a duplicate
                mp[cur]++;  // increase it to 2, so that no duplicates are stored
            }
            else mp[cur] = 1;
            
            i++;
        }

        return ans;
    }
};