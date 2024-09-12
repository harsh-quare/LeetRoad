class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mp;
        for(auto s: words){
            int mask = 0;
            for(auto ch: s){
                mask |= 1 << (ch-'a');
                // cout << mask << " ";
                // cout << 1 << (ch-'a') << " ";
            }
            // cout << endl;
            // cout << mask << endl;
            mp[mask]++;
        }

        int cnt = 0;
        for(auto x: mp){
            cnt += (x.second - 1) * x.second / 2;
        }

        return cnt;
    }
};