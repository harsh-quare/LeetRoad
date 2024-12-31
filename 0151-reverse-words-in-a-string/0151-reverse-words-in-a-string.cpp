class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0, j= 0;

        while(j < n){
            while(j < n && s[j] == ' '){
                j++;
            }
            
            if(j >= n) break;

            i = j; //new word start ho rha h, i pointer ko start pe betha de
            while(j < n && s[j] != ' '){
                j++;
            }

            st.push(s.substr(i, j-i));
        }

        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
            ans = ans + " ";
        }

        ans.pop_back();

        return ans;
    }
};