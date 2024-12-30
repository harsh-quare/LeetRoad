class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int& x: tasks){
            mp[x]++;
        }

        // for(auto it: mp){
        //     cout << it.first << " " << it.second << endl;
        // }

        int cnt = 0;
        for(auto& it: mp){
            if(it.second < 2) return -1;
            else if(it.second % 3 == 0) cnt += (it.second / 3);
            else{
                int ops = it.second / 3;
                int rem = it.second % 3;
                if(rem == 2){
                    cnt += (ops + 1); //ops number of operations with '3' and 1 opn with '2'
                }
                else{
                    cnt += (ops-1) + 2;  //ops-1 number of operations with '3' and 2 opn with '2'
                }
            }
            // cout << cnt << endl;
        }

        return cnt;
    }
};