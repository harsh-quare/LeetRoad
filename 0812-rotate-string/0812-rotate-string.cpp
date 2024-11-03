class Solution {
public:
    bool rotateString(string s, string goal) {
        //Method#2
        if(s.length() != goal.length()){
            return false;
        }

        s += s;

        //check if goal is a substring of the concatenated string
        return s.find(goal) != string::npos;
    }
};