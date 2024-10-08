class Solution {
public:
    int minSwaps(string s) {
        // stack<char> st;
        int size = 0;

        for(char c: s){
            if(c == '['){
                size++;
            }
            else if(size > 0){
                // st.pop();  //balancing closing bracket with an opening bracket int the stack
                size--;
            }
        }
        
        // (Number of opening_brackets + 1) / 2;
        return (size + 1) / 2;
    }
};