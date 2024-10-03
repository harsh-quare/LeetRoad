class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        if(k == 1) return 'a';
        int n = op.size();
        int type;
        long long len = 1, nextk;

        for(int i = 0; i<n; i++){
            len *= 2;
            if(len >= k){
                type = op[i];
                nextk = k - len/2;
                break;
            }
        }

        char res = kthCharacter(nextk, op);
        if(type == 0){
            return res;
        }
        if(res == 'z') return 'a';
        return res + 1;
    }
};