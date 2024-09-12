class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto s: words){
            int mask = 0;
            for(auto ch: s){
                mask |= 1 << (ch-'a');
                // cout << mask << " ";
                // cout << 1 << (ch-'a') << " ";
            }
            // cout << endl;
            // cout << mask << endl;
            ans += mp[mask]++;
        }

        return ans;
    }
};