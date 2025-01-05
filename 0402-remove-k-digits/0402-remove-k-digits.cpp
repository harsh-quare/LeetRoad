class Solution {
public:
    string removeKdigits(string num, int k) {
        // we want to remove larger digits from the left of the string
        // traverse and maintain a monotonic stack

        int n = num.size();
        if(k == n) return "0";

        stack<int> st;
        for(int i = 0; i < n; i++){
            int dig = num[i] - '0';
            while(k > 0 && !st.empty() && st.top() > dig){
                st.pop();
                k--;
            }

            st.push(dig);
        }

        // agar kisi bhi digit ko remove kiya hi nhi, qki already monotonically increasing me h, to usme se last ke k chars remove krdo
        if(k > 0){
            while(k--){
                st.pop();
            }
        }
        

        string ans = "";
        while(!st.empty()){
            ans += (char)(st.top() + '0');
            st.pop();
        }

        //remove trailing zeros, because we now have the revered string due to stack
        int i = ans.size()-1;
        while(i >= 0 && ans[i] == '0'){
            i--;
            ans.pop_back();
        }

        if(ans.size() == 0) return "0";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};