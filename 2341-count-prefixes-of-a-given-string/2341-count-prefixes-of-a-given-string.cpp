class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            string cur = words[i];
            if(s.find(cur) == 0) cnt++;
        }

        return cnt;
    }
};