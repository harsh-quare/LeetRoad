class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n+1, 0);
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i];

            string word = words[i];
            int sz = word.size();
            if(sz > 0 && isVowel(word[0]) && isVowel(word[sz-1])){
                pref[i+1] += 1;
            }
        }

        vector<int> ans;

        for(auto& q: queries){
            int l = q[0], r = q[1];
            int cnt = pref[r+1] - pref[l];

            ans.push_back(cnt);
        }

        return ans;
    }
};