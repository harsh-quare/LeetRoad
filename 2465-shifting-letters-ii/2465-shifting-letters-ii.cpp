class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> p(n + 1, 0);

        for(auto& it : shifts){
            int st = it[0];
            int e = it[1];
            int dir = it[2];

            if(dir == 1){
                p[st] += 1;
                if(e + 1 < n) p[e + 1] -= 1;
            } 
            else{
                p[st] -= 1;
                if(e + 1 < n) p[e + 1] += 1;
            }
        }

        // for(int i = 0; i <= n; i++){
        //     cout << p[i] << " ";
        // }

        int rsum = 0;
        for(int i = 0; i < n; i++){
            rsum += p[i];
            int pos = s[i] - 'a';
            int new_pos = (pos + rsum) % 26;
            if (new_pos < 0) new_pos += 26;
            s[i] = 'a' + new_pos;
        }

        return s;
    }
};
