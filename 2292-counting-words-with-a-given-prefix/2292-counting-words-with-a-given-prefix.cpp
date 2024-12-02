class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(s.find(pref) == 0) cnt++;  //agar 0-index pe pref mil gya, string 's' me
        }

        return cnt;
    }
};