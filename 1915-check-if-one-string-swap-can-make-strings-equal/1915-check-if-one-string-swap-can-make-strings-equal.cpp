class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> idc;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt > 2) return false;
                idc.push_back(i);
            }
        }

        if(cnt == 0) return true;
        if(cnt == 1) return false;

        int id1 = idc[0];
        int id2 = idc[1];

        if(s1[id1] != s2[id2] || s1[id2] != s2[id1]) return false;
        return true;
    }
};