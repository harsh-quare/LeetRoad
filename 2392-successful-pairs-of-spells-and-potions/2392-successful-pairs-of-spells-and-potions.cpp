class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());

        vector<int> pairs(n);
        for(int i= 0; i < n; i++){
            int spell = spells[i];
            long long minPotionExpected = success / spell;
            if(success % spell != 0) minPotionExpected++;

            auto it = lower_bound(potions.begin(), potions.end(), minPotionExpected);
            int cnt = potions.end() - it;

            pairs[i] = cnt;
        }

        return pairs;
    }
};