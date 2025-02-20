class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // converting into decimal and then checking one by one
        int n= nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            string bin = nums[i];
            int m = bin.size();
            int dec = 0;
            for(int j = m-1; j >= 0; j--){
                dec += (bin[j] - '0')*(1 << (m-1-j));
            }

            st.insert(dec);
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