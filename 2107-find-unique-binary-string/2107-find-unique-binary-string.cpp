class Solution {
public:
    string generate(int n, unordered_set<string>& st, string cur){
        if(cur.size() == n){
            return st.count(cur) > 0 ? "" : cur;
        }

        string addZero = generate(n, st, cur + "0");
        if(addZero != ""){
            return addZero;
        }

        return generate(n, st, cur + "1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // generating all n-bit binary strings
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        // string cur = "";
        return generate(n, st, "");
    }
};