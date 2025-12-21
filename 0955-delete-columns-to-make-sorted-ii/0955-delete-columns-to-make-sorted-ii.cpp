class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs.size(), m = strs[0].size(), count = 0;
        
        vector<bool> done(n); // done order of str[i] and str[i + 1]

        for(int i = 0; i < m; i++){
            bool check = true;
            for(int j = 0; j < n-1; j++){
                if(!done[j] && strs[j][i] > strs[j + 1][i]){
                    ans++;
                    check = false;
                    break;
                }
            }
            
            if(check){
                for(int j = 0; j < n-1; j++){
                    if(!done[j] && strs[j][i] < strs[j + 1][i]){
                        done[j] = true;
                        ++count;
                    }
                }
                if(count == n-1) break;
            }
        }

        return ans;
    }
};