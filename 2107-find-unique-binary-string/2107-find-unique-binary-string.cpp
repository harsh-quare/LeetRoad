class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // converting into decimal and then checking one by one
        int n= nums.size();
        unordered_set<int> st;
        for(string& num: nums){
            st.insert(stoi(num, 0, 2));  // stoi(string, position, int base)
        }

        for(int num = 0; num <= n; num++){  //instead of checking every number from 0 to 2^n - 1, we can check from 0 to n, means a total of n+1 numbers. Because the array size is n, hence we are checking one more number, guranteed one number out of them will be missing.
            if(st.find(num)==st.end()){
                // convert int to binary string
                string temp = bitset<16>(num).to_string();
                return temp.substr(16-n, n);
            }
        }

        return "";
    }
};