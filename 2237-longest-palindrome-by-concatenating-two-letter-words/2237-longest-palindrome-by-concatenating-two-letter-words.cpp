class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;

        unordered_map<string, int> mp;
        for(auto& s: words){
            string rev = s;
            swap(rev[0], rev[1]);

            if(mp.find(rev) != mp.end()){
                ans += 4;
                mp[rev]--;
                if(mp[rev] == 0) mp.erase(rev);
            }
            else{
                mp[s]++;
            }
        }

        for(auto& [s, f]: mp){
            if(s[0] == s[1]){
                if(f > 0){  // if a "xx" guys is remaining, add one of them, and then leave
                    ans += 2;
                    break;
                }
            }
        }

        return ans;
    }
};