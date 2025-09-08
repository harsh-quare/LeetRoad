class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            string a = to_string(i), b=to_string(n-i);

            if(a.find('0') != string::npos || b.find('0') != string::npos){
                continue;
            }
            
            return {i, n-i};
        }
        return {};
    }
};