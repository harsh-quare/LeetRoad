class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(k == 0) ans.push_back(0);
            else if(k > 0){
                int val = 0;
                int j = 0;
                while(j < k){
                    val += code[(i+1 + j + n) % n];
                    j++;
                }
                ans.push_back(val);
            }
            else{
                int val = 0;
                int j = 0;
                while(j < abs(k)){
                    val += code[(i-1 - j + n) % n];
                    j++;
                }
                ans.push_back(val);
            }
        }

        return ans;
    }
};