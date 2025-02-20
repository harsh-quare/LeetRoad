class Solution {
public:
    string generate(int n, unordered_set<string>& st, string cur){
        if(cur.size() == n){
            return st.count(cur) > 0 ? "" : cur;
        }

        for(char c: {'0', '1'}){
            string bin = generate(n, st, cur+c);
            if(!bin.empty()) return bin;
        }

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // generating all n-bit binary strings
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        return generate(n, st, "");
    }
};