class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32, 0);
        for(int i = 0; i < candidates.size(); i++){
            int idx = 0;
            int num = candidates[i];
            while(num){
                if(num & 1){
                    bits[idx]++;
                }
                num >>= 1;
                idx++;
            }
        }

        int maxi = 0;
        // for(int i = 0; i < 32; i++){
            // maxi = max(maxi, bits[i]);
        // }
        maxi= *max_element(bits.begin(), bits.end());
        
        return maxi;
    }
};