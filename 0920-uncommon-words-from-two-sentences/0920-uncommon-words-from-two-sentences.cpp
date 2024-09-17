class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int i = 0, j = 0;
        int n = s1.size();
        while(i < n){
            string s = "";
            while(j < n && s1[j] != ' '){
                s += s1[j++];
            }
            // cout << s << endl;
            mp[s]++;
            j++;
            i = j;
        }

        vector<string> ans;

        i = 0, j = 0;
        int m = s2.size();
        while(i < m){
            string s = "";
            while(j < m && s2[j] != ' '){
                s += s2[j++];
            }
            mp[s]++;
            j++;
            i = j;
        }

        for(auto x: mp){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};