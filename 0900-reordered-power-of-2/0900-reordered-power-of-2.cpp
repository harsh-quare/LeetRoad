class Solution {
public:
    string toSortedString(int n){
        string s = to_string(n);
        sort(s.begin(), s.end());

        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = toSortedString(n);

        for(int p = 0; p <= 30; p++){
            if(s == toSortedString(1 << p)){
                return true;
            }
        }

        return false;
    }
};