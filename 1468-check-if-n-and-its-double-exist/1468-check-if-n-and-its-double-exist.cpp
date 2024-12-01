class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto& num: arr){
            if(st.empty()){
                st.insert(num);
            }
            else{
                if(st.find(2*num) != st.end() || (st.find(num/2) != st.end() && (num/2) * 2 == num)){
                    return true;
                }
                st.insert(num);
            }
        }

        return false;
    }
};