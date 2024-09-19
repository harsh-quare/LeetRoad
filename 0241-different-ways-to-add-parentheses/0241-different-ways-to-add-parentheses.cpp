class Solution {
public:
    vector<int> solve(string s){
        vector<int> ans;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> left_side = solve(s.substr(0, i));  //left se solve krke le aao
                vector<int> right_side = solve(s.substr(i+1));   //right se solve krke le aao
                
                //compute and store all possible answers after combining both sides with current sign
                for(auto l: left_side){
                    for(auto r: right_side){
                        if(s[i] == '+') ans.push_back(l+r);
                        else if(s[i] == '-') ans.push_back(l-r);
                        else if(s[i] == '*') ans.push_back(l*r);
                    }
                }
            }
        }

        if(ans.size() == 0) ans.push_back(stoi(s));  //if there were no operators, string itself is the answer
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};