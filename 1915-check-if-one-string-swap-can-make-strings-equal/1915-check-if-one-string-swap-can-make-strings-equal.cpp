class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        vector<int> idc;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                idc.push_back(i);
            }
        }

        return idc.size() == 2 && s1[idc[0]] == s2[idc[1]] && s1[idc[1]] == s2[idc[0]];
    }
};