class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        // unordered_map<char, int> mp;
        vector<int> mp(26, 0);

        for(auto& ch: s){  // O(n)
            mp[ch-'a']++;
        }

        // O(t*n) => O(10^5 * 10^5)
        while(t--){  // O(t)
            // unordered_map<char, int> temp;
            vector<int> temp(26, 0);

            for(int i = 0; i < 26; i++){ // O(26)
                char ch = i + 'a';
                int freq = mp[i];

                if(ch != 'z'){
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % mod;
                }
                else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % mod;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % mod;
                }
            }

            mp = move(temp);  // instead of using mp = temp, which copies everything from temp to mp, we use mpve(temp) which moves everything from temp to mp
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = (ans + mp[i]) % mod;
        }

        return ans;
    }
};