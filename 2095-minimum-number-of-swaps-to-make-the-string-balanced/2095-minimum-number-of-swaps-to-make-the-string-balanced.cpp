class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char c: s){
            if(c == '['){
                st.push(c);
            }
            else if(!st.empty()){
                st.pop();  //balancing closing bracket with an opening bracket int the stack
            }
        }
        
        // (Number of opening_brackets + 1) / 2;
        return (st.size() + 1) / 2;
    }
};