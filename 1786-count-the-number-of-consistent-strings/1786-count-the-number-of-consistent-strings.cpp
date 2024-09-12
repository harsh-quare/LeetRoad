class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> alw(26, 0);
        int cnt = 0;
        int ans = 0;
        for(auto ch: allowed){
            if(alw[ch-'a'] == 0) cnt++;
            alw[ch-'a']++;
        }

        for(auto s: words){
            unordered_map<char, int> mp;
            bool isValid = true;
            for(auto ch: s){
                if(alw[ch-'a'] == 0) {   //agar ye wala character allowed string me h hi nhi, 
                    //to ye string valid nhi h, isko process krna band karo
                    isValid = false; 
                    break;
                }
                mp[ch]++;
            }

            if(isValid == true) ans++;
        }

        return ans;
    }
};