class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(auto c: word){
            freq[c-'a']++;
        }

        int ans = word.size();  // max answer

        // try every character freq as the min in resulting string, that means it will allow frequencies from [f,f+k], lower ones will be reduced to zero and >f+k, ones will be reduced to f+k

        for(int i = 0; i < 26; i++){
            int cnt = 0;
            int curMinFreq = freq[i];
            for(int j = 0; j < 26; j++){
                if(i == j) continue;

                if(freq[j] < curMinFreq) cnt += freq[j];  // delete all occ of it
                else if(abs(freq[j] - curMinFreq) > k){
                    // int diff = freq[j] - freq[i]
                    // int extra = diff - k
                    cnt += abs(freq[j] - curMinFreq) - k;
                }
            }

            ans = min(ans, cnt);
        }

        return ans;
    }
};