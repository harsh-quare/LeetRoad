class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        if(n % 2 == 1) ans.push_back(0);
        int val = 1;
        for(int i = 0; i < n/2; i++){
            ans.push_back(val);
            ans.push_back(-val);
            val++;
        }
        
        return ans;
    }
};