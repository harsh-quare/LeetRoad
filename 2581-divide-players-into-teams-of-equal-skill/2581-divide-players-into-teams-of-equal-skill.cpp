class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();

        if(n == 2) return (long long)skill[0]*skill[1];

        int equalSum = skill[0] + skill[n-1];
        long long chemistry = skill[0]*skill[n-1];

        for(int i = 1; i < n/2; i++){
            if(skill[i] + skill[n-i-1] != equalSum) return -1;
            else{
                chemistry += (long long)skill[i]*skill[n-i-1];
            }
        }

        return chemistry;
    }
};