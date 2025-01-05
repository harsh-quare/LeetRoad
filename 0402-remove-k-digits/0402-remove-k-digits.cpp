class Solution {
public:
    string removeKdigits(string num, int k) {
        // we want to remove larger digits from the left of the string
        // traverse and maintain a monotonic stack

        int n = num.size();
        if(k == n) return "0";

        stack<char> st;
        for(int i = 0; i < n; i++){
            int dig = num[i] - '0';
            while(k > 0 && !st.empty() && (st.top()-'0') > dig){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // agar kisi bhi digit ko remove kiya hi nhi, qki already monotonically increasing me h, to usme se last ke k chars remove krdo
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        cout << ans << endl;

        //remove trailing zeros, because we now have the revered string due to stack
        while(ans.size() != 0 && ans.back() == '0'){
            ans.pop_back();
        }

        if(ans.size() == 0) return "0";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};