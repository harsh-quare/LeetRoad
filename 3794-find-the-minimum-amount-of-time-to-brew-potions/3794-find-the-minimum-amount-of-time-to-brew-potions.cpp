class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> khatam(n, 0);

        for(int j = 0; j < m; j++){
            // iterate over mana's => potions
            khatam[0] += skill[0]*mana[j];
            
            // iterate over wizards => forward => try to brute forcely assign time => depending upon (i-1) guy and (j-1) potion's ending time
            for(int i = 1; i < n; i++){
                khatam[i] = max(khatam[i-1], khatam[i]);
                khatam[i] += 1LL * mana[j] * skill[i];
            }

            // iterate backward and synchronize the time
            // keep correcting from last to first
            for(int i = n-1; i > 0; i--){
                khatam[i-1] = khatam[i] - 1LL * skill[i] * mana[j];
            }
        }

        return khatam[n-1];
    }
};