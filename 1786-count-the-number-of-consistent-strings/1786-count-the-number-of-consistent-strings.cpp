class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int mask = 0;  // 000000000000000...
        for(auto ch: allowed){
            mask |= (1 << (ch-'a'));  // a hua to 0th bit set, then b hua to 1st bit set and so on...
        }

        for(auto s: words){
            bool isValid = true;
            for(auto ch: s){
                //to check if nth bit is set or not
                //right shift mask n times and & with 1 to check
                if(((mask >> (ch-'a')) & 1) == 0) {   //agar ye wala character allowed string me h hi nhi, 
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