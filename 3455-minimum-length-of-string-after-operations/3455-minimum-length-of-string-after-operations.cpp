class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(auto& ch: s){
            freq[ch-'a']++;
        }

        int len = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] <= 2) len += freq[i];
            else{    // if(freq[i] > 2)        
                if(freq[i] % 2 != 0) len += 1;  // agar 3,5,7 aisa kuch h, to saare pairs left right se nikal jayenge, ek bach jayega
                else len += 2;  // otherwise, agar 4,6,8 aisa h, to hamesha last me 2 bach jayenge, baaki sab nikal jayenge pair banke
            }
        }

        return len;
    }
};