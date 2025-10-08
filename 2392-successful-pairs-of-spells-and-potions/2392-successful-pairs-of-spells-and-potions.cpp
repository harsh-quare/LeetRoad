class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> pairs(n);
        for(int i= 0; i < n; i++){
            // int spell = spells[i];
            // long long minPotionExpected = success / spell;
            // if(success % spell != 0) minPotionExpected++;

            // auto it = lower_bound(potions.begin(), potions.end(), minPotionExpected);
            // int cnt = potions.end() - it;

            // pairs[i] = cnt;

            int left = 0;
            int right = m-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if((long long)spells[i] * potions[mid] >= success){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }

            pairs[i] = m - left;
        }

        return pairs;
    }
};