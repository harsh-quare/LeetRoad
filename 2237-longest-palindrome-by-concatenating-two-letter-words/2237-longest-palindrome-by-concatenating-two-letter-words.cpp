class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // we need to count, how many words are "xx", means both characters same
        // we also need to count how many words have their mirror opposite
        int ans = 0;
        int bothSame = 0;
        int mirrorPair = 0;

        unordered_map<string, int> mp;
        for(string& s: words){
            mp[s]++;

            if(s[0] != s[1]){
                string rev = s;
                reverse(rev.begin(), rev.end());
                if(mp.find(rev) != mp.end()){
                    mirrorPair++;
                    mp[rev]--;
                    mp[s]--;

                    if(mp[rev] == 0) mp.erase(rev);
                    if(mp[s] == 0) mp.erase(s);
                }
            }
            else bothSame++;
        }

        // mirrorPair wale saare words ham palindrome me use kr skte h
        // but, jo same char wale words h, unme hame sab use nhi kr skte
        // ham unme se total odd number of times use kr skte h

        ans += mirrorPair*4;
        bool rem = false;

        for(auto& [s, f]: mp){
            if(s[0] == s[1]){
                if(f % 2 != 0){
                    rem = true;
                    ans += (f-1)*2;
                }
                else ans += f*2;
            }
        }

        if(rem == 0) return ans;
        else return ans + 2;  // ek extra or le skte h, agar kisi ke paas extra tha, to keep it in middle
    }
};