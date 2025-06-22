class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int i = 0;
        vector<string> ans;
        while(i+k <= n){
            string cur = s.substr(i, k);
            ans.push_back(cur);
            i += k;
        }
        if(i < n){
            // remaining string part ko daal do, and remaining places pe 'fill' ki padding kr do
            string cur = s.substr(i);
            int remSz = k - cur.size();
            for(int j = 0; j < remSz; j++){
                cur += fill;
            }
            ans.push_back(cur);
        }

        return ans;
    }
};