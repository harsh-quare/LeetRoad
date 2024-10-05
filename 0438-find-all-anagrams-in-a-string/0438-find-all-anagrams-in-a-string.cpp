class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        string r, t;
        if(p.length() <= s.length()){
            r = p, t = s;
        }
        else{
            return ans;
        }

        int l = r.length();
        int i = 0, j = 0;
        vector<int> f1(26, 0);
        for(auto c: r) f1[c-'a']++;

        vector<int> freq(26, 0);

        while(j < t.length()){
            freq[t[j]-'a']++;

            while(j-i+1 > l){
                freq[t[i]-'a']--;
                i++;
            }

            bool valid = true;
            for(int k = 0; k < 26; k++){
                if(f1[k] != freq[k]) valid = false;
            }

            if(valid == true) ans.push_back(i);
            j++;
        }

        return ans;
    }
};