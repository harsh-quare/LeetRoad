class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> alw(26, 0);
        int ans = 0;
        for(auto ch: allowed){
            alw[ch-'a'] = 1;
        }

        for(auto s: words){
            bool isValid = true;
            for(auto ch: s){
                if(alw[ch-'a'] == 0) {   //agar ye wala character allowed string me h hi nhi, 
                    //to ye string valid nhi h, isko process krna band karo
                    isValid = false; 
                    break;
                }
            }
            if(isValid == true) ans++;
        }

        return ans;
    }
};