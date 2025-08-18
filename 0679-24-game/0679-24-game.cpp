class Solution {
public:
    const double eps = 1e-6;

    bool dfs(vector<double>& nums){
        // base case: Only one element left in the active element's array => check if it's 24
        if(nums.size() == 1){
            return fabs(nums[0] - 24) < eps;
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                // take all the possible pairs from active elements array nums
                if(i == j) continue;

                vector<double> newNums;
                for(int k = 0; k < nums.size(); k++){
                    if(k != i && k != j){
                        newNums.push_back(nums[k]);
                    }
                }

                vector<double> possibleValsWithPair = compute(nums[i], nums[j]);
                for(double x: possibleValsWithPair){
                    newNums.push_back(x);
                    
                    if(dfs(newNums)) return true;

                    newNums.pop_back();
                }
            }
        }

        return false;
    }

    vector<double> compute(double a, double b){
        vector<double> help;
        help.push_back(a + b);
        help.push_back(a - b);
        help.push_back(b - a);
        help.push_back(a * b);
        // ensure tackling division by 0
        if(fabs(b) > eps) help.push_back(a / b);
        if(fabs(a) > eps) help.push_back(b / a);

        return help;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> help(cards.begin(), cards.end());
        return dfs(help);
    }
};