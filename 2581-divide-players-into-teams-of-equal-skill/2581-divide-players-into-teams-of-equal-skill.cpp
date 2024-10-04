class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long total = 0;

        unordered_map<int, int> mp;
        for(auto x: skill){
            total += x;
            mp[x]++;
        }

        int groups = n/2;
        if(total % groups != 0) return -1;
        
        long long equalSum = total / groups;
        long long chemistry = 0;

        for(auto it: mp){
            int x = it.first;
            long long needed = equalSum - x;
            if(mp.find(needed) == mp.end() || mp[x] != mp[needed]) return -1;
            else{
                if(mp[x] != -1 && mp[needed] != -1){
                    long long curChem = mp[x]*x*needed;
                    if(x == needed) curChem /= 2;  //mp[x] dono ke liye same h and 2 baar use ho gya ek tarah se upar
                    chemistry += curChem;
                    mp[x] = -1;
                    mp[needed] = -1;
                }
            }
        }   

        return chemistry;     
    }
};