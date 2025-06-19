class Solution {
public:
    string simplifyPath(string path) {
        // keep pushing in stack, and the process
        int n = path.size();
        int i = 0;
        stack<string> st;
        while(i < n){
            // consecutive '/' ko skip krdo
            while(i < n && path[i] == '/'){
                i++;
            }

            // yaha aagye mtlb koi alphabet encounter hua h
            string temp = "";
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else if(temp != "" && temp != "."){
                st.push(temp);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.size() == 0) return "/";

        return ans;
    }
};