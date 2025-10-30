class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;

        int prevMax = 0;
        for(int i = 0; i < target.size(); i++){
            if(target[i] > prevMax){
                int extra_ops = target[i] - prevMax;
                
                ans += extra_ops;
            }

            prevMax = target[i];
        }

        return ans;
    }
};