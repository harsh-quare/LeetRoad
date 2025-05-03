class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> freq(7, 0);
        vector<int> topFreq(7, 0), botFreq(7, 0);
        int n = tops.size();

        for(int i = 0; i < n; i++){
            int t = tops[i];
            int b = bottoms[i];

            if(t == b) freq[t]++;
            else{
                freq[t]++;
                freq[b]++;
            }

            // for tops freq
            topFreq[t]++;
            botFreq[b]++;
        }

        int ans = n;
        for(int i = 0; i < 7; i++){
            if(freq[i] == n){
                ans = min(ans, min(n - topFreq[i], n - botFreq[i]));
            }
        }

        return (ans == n) ? -1 : ans;
    }
};