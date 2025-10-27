class Solution {
public:
    int countSec(string& sec){
        int cnt = 0;
        for(char& c: sec){
            cnt += (c == '1');
        }

        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        // I just need how many security devices are encountered in a latest row with non-zero number of sec devices
        int ans = 0;
        int prevSecCnt = 0;

        for(int i = 0; i < bank.size(); i++){
            int curSecCnt = countSec(bank[i]);

            if(curSecCnt > 0){
                ans += curSecCnt * prevSecCnt;
                prevSecCnt = curSecCnt;
            }

        }

        return ans;
    }
};