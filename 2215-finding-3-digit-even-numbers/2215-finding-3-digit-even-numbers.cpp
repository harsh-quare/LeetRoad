class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;

        // if the resulting integer is "ijk" => i => [1,9]; j => [0,9]; k => {0,2,4,6,8}
        // so we need to track, which digits do we have
        vector<int> mp(10, 0);
        for(int& d: digits){
            mp[d]++;
        }

        for(int i = 1; i <= 9; i++){
            if(mp[i] == 0) continue;  // can't use this digit

            mp[i]--;  // use it once as leftmost dig
            for(int j = 0; j <= 9; j++){
                if(mp[j] == 0) continue;  // can't use this digit

                mp[j]--;  // use it once as middle dig 
                for(int k = 0; k <= 8; k+=2){
                    if(mp[k] == 0) continue;  // can't use this digit

                    mp[k]--;  // use it once as rightmost dig
                    int num = i*100 + j*10 + k*1;
                    ans.push_back(num);

                    mp[k]++;  // after using and building all possible integers, now remove it
                }

                mp[j]++;  // after using and building all possible integers, now remove it
            }

            mp[i]++;  // after using and building all possible integers, now remove it
        }

        return ans;
    }
};