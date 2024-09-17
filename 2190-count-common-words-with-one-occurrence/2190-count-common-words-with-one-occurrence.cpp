class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        for(auto s: words1){
            if(mp.find(s) != mp.end()) mp[s] = -1;
            else mp[s] = 1;
        }
        for(auto s: words2){
            if(mp.find(s) != mp.end() && mp[s] == 1){ 
                mp[s]= 0;
            }
            else if(mp.find(s) != mp.end()){
                mp[s] = -1;
            }
        }

        int cnt = 0;
        for(auto x: mp){
            if(x.second == 0) {
                cnt++;
                // cout << x.first << endl;
            }
        }
        return cnt;
    }
};