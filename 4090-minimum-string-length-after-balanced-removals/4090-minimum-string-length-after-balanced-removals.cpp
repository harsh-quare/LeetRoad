class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int as = 0;
        for(char c: s){
            as += (c == 'a');
        }

        return abs(2*as - n);
    }
};