class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string s1 = words[i];
            for(int j = i + 1; j < n; j++){
                string s2 = words[j];

                if(s1.length() > s2.length()) continue;
                else{
                    if((s2.substr(0, (int)s1.length()) == s1) && 
                       (s2.substr((int)s2.length()-(int)s1.length(), (int)s1.length()) == s1)) 
                    cnt++;
                }
            }
        }

        return cnt;
    }
};