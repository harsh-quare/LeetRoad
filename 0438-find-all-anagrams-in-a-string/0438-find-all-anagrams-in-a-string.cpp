class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length() > s.length()) return ans;

        int l = p.length();
        int i = 0, j = 0;
        vector<int> f1(26, 0);
        for(auto c: p) f1[c-'a']++;

        vector<int> f2(26, 0);

        while(j < s.length()){
            f2[s[j]-'a']++;

            while(j-i+1 > l){
                f2[s[i]-'a']--;
                i++;
            }

            bool valid = true;
            for(int k = 0; k < 26; k++){
                if(f1[k] != f2[k]) valid = false;
            }

            if(valid == true) ans.push_back(i);
            j++;
        }

        return ans;
    }
};