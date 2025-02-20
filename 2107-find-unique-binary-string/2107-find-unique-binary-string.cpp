class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // converting into decimal and then checking one by one
        int n= nums.size();
        unordered_set<int> st;
        for(string& num: nums){
            st.insert(stoi(num, 0, 2));  // stoi(string, position, int base)
        }

        for(int num = 0; num <= (1 << (n-1)); num++){
            if(st.find(num)==st.end()){
                // convert int to binary string
                string temp = bitset<16>(num).to_string();
                return temp.substr(16-n, n);
            }
        }

        return "";
    }
};