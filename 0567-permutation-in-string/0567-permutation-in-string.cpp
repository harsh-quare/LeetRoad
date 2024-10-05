class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string s, t;
        if(s1.length() <= s2.length()){
            s = s1, t = s2;
        }
        else{
            return false;
        }

        int l = s.length();
        int i = 0, j = 0;
        vector<int> f1(26, 0);
        for(auto c: s) f1[c-'a']++;

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

            if(valid == true) return true;
            j++;
        }

        return false;
    }
};