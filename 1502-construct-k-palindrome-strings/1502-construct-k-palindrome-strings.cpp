class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        vector<int> f(26, 0);
        for(auto& c: s){
            f[c-'a']++;
        }
        
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(f[i] % 2 == 1) cnt++;
        }

        if(cnt > k) return false;
        return true;
    }
};